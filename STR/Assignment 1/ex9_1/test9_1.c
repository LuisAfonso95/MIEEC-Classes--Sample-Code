



#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sched.h>

#include "../common_files/func.h"
#include "../common_files/rtai_mine.h"
#include "../common_files/timespec_math.h"



/* Activation periods */
#define PERIOD1_MS 100
#define PERIOD2_MS 200
#define PERIOD3_MS 360


/* Activation time for each thread */
struct timespec activation_time[3];

/*
  Variable to hold the worst response time
*/
struct timespec worse_response_time[3] = { {0,0}, {0,0}, {0,0}};


/**/
pthread_t thr[3];




/*
    Thread that runs f1().
    This thread also switches the priority order from RMPO to inverse RMPO at the
  set time.
*/
void* function1(void* arg){

  //wait so that all tasks activate at the same time
  while(rt_task_wait_period() == -1);

  while(1){


    f1(2,3);

    struct timespec response_time;
    //get execution end time
    clock_gettime(CLOCK_MONOTONIC, &response_time);

    //calculate response time
    struct timespec activation_time;
    rt_give_last_activation(&activation_time);
    response_time = timespec_diference(response_time, activation_time);

    //check if it's the worse response time so far
    struct timespec temp = timespec_diference(worse_response_time[0], response_time);
    if(temp.tv_sec < 0 || temp.tv_nsec < 0){
      worse_response_time[0] = response_time;
    }

    rt_task_wait_period();
  }

}


/*
    Thread that runs f2().
*/
void* function2(void* arg){
  //wait so that all tasks activate at the same time
  while(rt_task_wait_period() == -1);

  while(1){


    f2(2,3);

    struct timespec response_time;
    //get execution end time
    clock_gettime(CLOCK_MONOTONIC, &response_time);

    //calculate response time
    struct timespec activation_time;
    rt_give_last_activation(&activation_time);
    response_time = timespec_diference(response_time, activation_time);

    //check if it's the worse response time so far
    struct timespec temp = timespec_diference(worse_response_time[1], response_time);
    if(temp.tv_sec < 0 || temp.tv_nsec < 0){
      worse_response_time[1] = response_time;
    }

    rt_task_wait_period();

  }

}



/*
    Thread that runs f3().
    This thread also switches the priority order from inverse RMPO to RMPO at the
  set time.
*/
void* function3(void* arg){

  //wait so that all tasks activate at the same time
  while(rt_task_wait_period() == -1);

  while(1){


    f3(2,3);

    struct timespec response_time;
    //get execution end time
    clock_gettime(CLOCK_MONOTONIC, &response_time);

    //calculate response time
    struct timespec activation_time;
    rt_give_last_activation(&activation_time);
    response_time = timespec_diference(response_time, activation_time);

    //check if it's the worse response time so far
    struct timespec temp = timespec_diference(worse_response_time[2], response_time);
    if(temp.tv_sec < 0 || temp.tv_nsec < 0){
      worse_response_time[2] = response_time;
    }

    rt_task_wait_period();

  }
}

int main(){


  /* Set all activation to 2 seconds after the current time*/
  struct timespec dt; dt.tv_sec = 2; dt.tv_nsec = 0;
  clock_gettime(CLOCK_MONOTONIC, &activation_time[0]);
  for(int i = 1; i < 3; i++){
    activation_time[i] = activation_time[0];
    activation_time[i].tv_sec += dt.tv_sec;
  }
  activation_time[0].tv_sec += dt.tv_sec;

  // Lock the memory
  mlockall(MCL_CURRENT|MCL_FUTURE);

  /*
    For each thread change the scheduler to FIFO and set the priorities (right now
  in RMPO)
  */
  pthread_attr_t attr[3];
  pthread_attr_init(&attr[0]);
  pthread_attr_setschedpolicy(&attr[0], SCHED_FIFO);
  struct sched_param priority[3]; priority[0].sched_priority = sched_get_priority_max(SCHED_FIFO);
  pthread_attr_setschedparam(&attr[0],&priority[0]);
  pthread_attr_setinheritsched(&attr[0], PTHREAD_EXPLICIT_SCHED);


  pthread_attr_init(&attr[1]);
  pthread_attr_setschedpolicy(&attr[1], SCHED_FIFO);
  priority[1].sched_priority = sched_get_priority_max(SCHED_FIFO)-1;
  pthread_attr_setschedparam(&attr[1],&priority[1]);
  pthread_attr_setinheritsched(&attr[1], PTHREAD_EXPLICIT_SCHED);

  pthread_attr_init(&attr[2]);
  pthread_attr_setschedpolicy(&attr[2], SCHED_FIFO);
  priority[2].sched_priority = sched_get_priority_max(SCHED_FIFO)-2;
  pthread_attr_setschedparam(&attr[2],&priority[2]);
  pthread_attr_setinheritsched(&attr[2], PTHREAD_EXPLICIT_SCHED);

  /*
    Set threads affinity to CPU 0
  */
  cpu_set_t my_set;
  CPU_ZERO(&my_set);
  CPU_SET(0, &my_set);
  pthread_attr_setaffinity_np(&attr[0], sizeof(my_set), &my_set);
  pthread_attr_setaffinity_np(&attr[1], sizeof(my_set), &my_set);
  pthread_attr_setaffinity_np(&attr[2], sizeof(my_set), &my_set);

  /* Set the main thread to lowest priority */
  //important!! without this the response times changed between switches!
  pthread_t self = pthread_self();
  //pthread_setaffinity_np(self, sizeof(my_set), &my_set);
  pthread_setschedprio(self, sched_get_priority_min(SCHED_FIFO));




  /* Create all the threads */
  printf("======Starting in RMPO======\n");
  if(pthread_create(&(thr[0]), &attr[0], function1, NULL) < 0){
    printf("Error %s\n",strerror(errno));
    exit(0);
  }
  if(pthread_create(&(thr[1]), &attr[1], function2, NULL) < 0){
    printf("Error %s\n",strerror(errno));
    exit(0);
  }
  if(pthread_create(&(thr[2]), &attr[2], function3, NULL) < 0){
    printf("Error %s\n",strerror(errno));
    exit(0);
  }

  /* Configure the periods and start times for the tasks using rtai like functions */
  struct timespec _dt; _dt.tv_sec = 0; _dt.tv_nsec = (PERIOD1_MS)* 1000000;
  rt_task_make_periodic(&thr[0], activation_time[0], _dt);
  _dt.tv_sec = 0; _dt.tv_nsec = (PERIOD2_MS)* 1000000;
  rt_task_make_periodic(&thr[1], activation_time[1], _dt);
  _dt.tv_sec = 0; _dt.tv_nsec = (PERIOD3_MS)* 1000000;
  rt_task_make_periodic(&thr[2], activation_time[2], _dt);



  /*
      This will sleep for 5 seconds, then cancel all threads and print the worst
    response times.
  */
  while(1){

    sleep(5);
    pthread_cancel(thr[0]);
    pthread_cancel(thr[1]);
    pthread_cancel(thr[2]);
    printf("1 - worse response time: %lds and %ldms\n", worse_response_time[0].tv_sec, worse_response_time[0].tv_nsec/1000000);
    worse_response_time[0].tv_sec = 0; worse_response_time[0].tv_nsec = 0;
    printf("2 - worse response time: %lds and %ldms\n", worse_response_time[1].tv_sec, worse_response_time[1].tv_nsec/1000000);
    worse_response_time[1].tv_sec = 0; worse_response_time[1].tv_nsec = 0;
    printf("3 - worse response time: %lds and %ldms\n", worse_response_time[2].tv_sec, worse_response_time[2].tv_nsec/1000000);
    worse_response_time[2].tv_sec = 0; worse_response_time[2].tv_nsec = 0;

    exit(0);
    //pause();
  }


}
