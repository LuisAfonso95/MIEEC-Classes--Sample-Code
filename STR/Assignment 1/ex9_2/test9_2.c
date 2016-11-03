



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

/*
  Logging variables for matlab

  activation_timestamp - the time at which the task was suposed to activate
  dt1_timestamp - the time at which the task started (not to calculate response time)
  dt2_timestamp - time at which the function finished executing (used to calculate response time)
  _counter - number of the sample
  priorities_change_logger - holds the time at which the priority change happened
*/
#define MatLab_sizes 400
struct timespec time1_activation_timestamp[MatLab_sizes];
struct timespec time1_dt1_timestamp[MatLab_sizes];
struct timespec time1_dt2_timestamp[MatLab_sizes];
int r1_counter =0;

struct timespec time2_activation_timestamp[MatLab_sizes];
struct timespec time2_dt1_timestamp[MatLab_sizes];
struct timespec time2_dt2_timestamp[MatLab_sizes];
int r2_counter =0;

struct timespec time3_activation_timestamp[MatLab_sizes];
struct timespec time3_dt1_timestamp[MatLab_sizes];
struct timespec time3_dt2_timestamp[MatLab_sizes];
int r3_counter =0;


struct timespec priorities_change_logger[MatLab_sizes];
int priorities_change_counter = 0;

/* Activation time for each thread */
struct timespec activation_time[3];

/*
  Variable to hold the worst response time
*/
struct timespec worse_response_time[3] = { {0,0}, {0,0}, {0,0}};

/*
  switch_time - time when to switch priority orders
  switch_dt - the time between priority switches
 */
struct timespec switch_time, switch_dt;

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
  struct timespec activation_time;
  rt_give_last_activation(&activation_time);

  //Log activation time
  time1_activation_timestamp[r1_counter] = activation_time;

  while(1){

    struct timespec temp;

    //Log execution start time
    clock_gettime(CLOCK_MONOTONIC, &temp);
    time1_dt1_timestamp[r1_counter] = temp;


    f1(2,3);



    //Log execution end time
    clock_gettime(CLOCK_MONOTONIC, &temp);
    time1_dt2_timestamp[r1_counter] = temp;
    struct timespec response_time;
    response_time = timespec_diference(time1_dt2_timestamp[r1_counter], time1_activation_timestamp[r1_counter]);
    r1_counter++;

    struct timespec temp2;
    temp2 = timespec_diference(worse_response_time[0], response_time);
    if(temp2.tv_sec < 0 || temp2.tv_nsec < 0){
      worse_response_time[0] = response_time;
    }

    //get priority of this thread to know if running RMPO
    struct sched_param teste; int testeint;
    pthread_getschedparam(thr[0],&testeint, &teste);
    int n = teste.sched_priority;

    //check if switch time was reached
    temp = timespec_diference(switch_time, temp);
    if(n == sched_get_priority_max(SCHED_FIFO) && (temp.tv_sec < 0 || temp.tv_nsec < 0) ){
      printf("Task 1 worse response time: %lds and %ldms\n", worse_response_time[0].tv_sec, worse_response_time[0].tv_nsec/1000000 );
      printf("Task 2 worse response time: %lds and %ldms\n", worse_response_time[1].tv_sec, worse_response_time[1].tv_nsec/1000000 );
      printf("Task 3 worse response time: %lds and %ldms\n", worse_response_time[2].tv_sec, worse_response_time[2].tv_nsec/1000000 );
      worse_response_time[0].tv_sec = 0; worse_response_time[0].tv_nsec = 0;
      worse_response_time[1].tv_sec = 0; worse_response_time[1].tv_nsec = 0;
      worse_response_time[2].tv_sec = 0; worse_response_time[2].tv_nsec = 0;
      printf("======Switch to inverse RMPO======\n");

      //Log time at which priority changed
      clock_gettime(CLOCK_MONOTONIC, &switch_time);
      priorities_change_logger[priorities_change_counter] = switch_time;
      priorities_change_counter++;

      //set switch_time to current time + switch_dt
      switch_time = timespec_sum(switch_time, switch_dt);

      //Switch task 1 and 3 priorities
      pthread_setschedprio(thr[2],sched_get_priority_max(SCHED_FIFO));
      pthread_setschedprio(thr[0],sched_get_priority_max(SCHED_FIFO)-2);

    }
    rt_task_wait_period();
    struct timespec activation_time;
    rt_give_last_activation(&activation_time);
    //Log activation time
    time1_activation_timestamp[r1_counter] = activation_time;
  }

}


/*
    Thread that runs f2().
*/
void* function2(void* arg){
  //wait so that all tasks activate at the same time
  while(rt_task_wait_period() == -1);
  struct timespec activation_time;
  rt_give_last_activation(&activation_time);
  //Log activation time
  time2_activation_timestamp[r2_counter] = activation_time;

  while(1){

    struct timespec temp;
    //Log execution start time
    clock_gettime(CLOCK_MONOTONIC, &temp);
    time2_dt1_timestamp[r2_counter] = temp;
    f2(2,3);

    //Log execution end time
    clock_gettime(CLOCK_MONOTONIC, &temp);
    time2_dt2_timestamp[r2_counter] = temp;
    struct timespec response_time;
    response_time = timespec_diference(time2_dt2_timestamp[r2_counter], time2_activation_timestamp[r2_counter]);
    r2_counter++;

    struct timespec temp2;
    temp2 = timespec_diference(worse_response_time[1], response_time);
    if(temp2.tv_sec < 0 || temp2.tv_nsec < 0){
      worse_response_time[1] = response_time;
    }

    rt_task_wait_period();

    struct timespec activation_time;
    rt_give_last_activation(&activation_time);
    //Log activation time
    time2_activation_timestamp[r2_counter] = activation_time;

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
  struct timespec activation_time;
  rt_give_last_activation(&activation_time);
  //Log activation time
  time3_activation_timestamp[r3_counter] = activation_time;
  while(1){

    struct timespec temp;
    //Log execution start time
    clock_gettime(CLOCK_MONOTONIC, &temp);
    time3_dt1_timestamp[r3_counter] = temp;

    f3(2,3);


    //Log execution end time

    clock_gettime(CLOCK_MONOTONIC, &temp);
    time3_dt2_timestamp[r3_counter] = temp;
    struct timespec response_time;
    response_time = timespec_diference(time3_dt2_timestamp[r3_counter], time3_activation_timestamp[r3_counter]);
    r3_counter++;

    struct timespec temp2;
    temp2 = timespec_diference(worse_response_time[2], response_time);
    if(temp2.tv_sec < 0 || temp2.tv_nsec < 0){
      worse_response_time[2] = response_time;
    }

    //get priority of this thread to know if running inverse RMPO
    struct sched_param teste; int testeint;
    pthread_getschedparam(thr[2],&testeint, &teste);
    int n = teste.sched_priority;

    //check if switch time was reached
    temp = timespec_diference(switch_time, temp);
    if(n == sched_get_priority_max(SCHED_FIFO) && (temp.tv_sec < 0 || temp.tv_nsec < 0) ){
      printf("Task 1 worse response time: %lds and %ldms\n", worse_response_time[0].tv_sec, worse_response_time[0].tv_nsec/1000000 );
      printf("Task 2 worse response time: %lds and %ldms\n", worse_response_time[1].tv_sec, worse_response_time[1].tv_nsec/1000000 );
      printf("Task 3 worse response time: %lds and %ldms\n", worse_response_time[2].tv_sec, worse_response_time[2].tv_nsec/1000000 );
      worse_response_time[0].tv_sec = 0; worse_response_time[0].tv_nsec = 0;
      worse_response_time[1].tv_sec = 0; worse_response_time[1].tv_nsec = 0;
      worse_response_time[2].tv_sec = 0; worse_response_time[2].tv_nsec = 0;

      printf("======Switch to RMPO======\n");

      //Log time at which priority changed
      clock_gettime(CLOCK_MONOTONIC, &switch_time);
      priorities_change_logger[priorities_change_counter] = switch_time;
      priorities_change_counter++;

      //set switch_time to current time + switch_dt
      switch_time = timespec_sum(switch_time, switch_dt);

      //Switch task 1 and 3 priorities
      pthread_setschedprio(thr[0],sched_get_priority_max(SCHED_FIFO));
      pthread_setschedprio(thr[2],sched_get_priority_max(SCHED_FIFO)-2);


    }
    rt_task_wait_period();
    struct timespec activation_time;
    rt_give_last_activation(&activation_time);
    //Log activation time
    time3_activation_timestamp[r3_counter] = activation_time;

  }
}


/*
  This function will create a file with 3 arrays with the for matlab
*/
void Dump_MatLab(){
  mode_t fdmode = 0666; // Permissions of acess at file
  int aux_f = open("ex9_2_MatLab_Values.txt",  O_CREAT|O_WRONLY|O_EXCL, fdmode); // Also creates the file
  if(  aux_f == -1){
    printf("Error opening the file: %s\n", strerror(errno));
    exit(0);
  }

  char a[] = "times = [";
  write(aux_f, a, strlen(a));
  for(int i = 0; i < MatLab_sizes; i++){
      char message[100];
      sprintf(message, "%ld  %ld  %ld  %ld  %ld  %ld  %ld  %ld  %ld  %ld  %ld  %ld;\n",
      time1_dt1_timestamp[i].tv_sec, time1_dt1_timestamp[i].tv_nsec/1000000,
      time1_dt2_timestamp[i].tv_sec, time1_dt2_timestamp[i].tv_nsec/1000000,

      time2_dt1_timestamp[i].tv_sec, time2_dt1_timestamp[i].tv_nsec/1000000,
      time2_dt2_timestamp[i].tv_sec, time2_dt2_timestamp[i].tv_nsec/1000000,

      time3_dt1_timestamp[i].tv_sec, time3_dt1_timestamp[i].tv_nsec/1000000,
      time3_dt2_timestamp[i].tv_sec, time3_dt2_timestamp[i].tv_nsec/1000000
    );
      write(aux_f, message, strlen(message));
  }
  char b[] = "];\n\n";
  write(aux_f, b, strlen(b));

  char c[] = "prio = [";
  write(aux_f, c, strlen(c));
  for(int i = 0; i < MatLab_sizes; i++){
      char message[50];
      sprintf(message, "%ld  %ld;\n",
      priorities_change_logger[i].tv_sec, priorities_change_logger[i].tv_nsec/1000000);
      write(aux_f, message, strlen(message)-1);
  }
  char d[] = "];\n\n";
  write(aux_f, d, strlen(d));

  char e[] = "activation = [";
  write(aux_f, e, strlen(e));
  for(int i = 0; i < MatLab_sizes; i++){
    char message[50];
    sprintf(message, "%ld  %ld  %ld  %ld  %ld  %ld;\n",
    time1_activation_timestamp[i].tv_sec, time1_activation_timestamp[i].tv_nsec/1000000,
    time2_activation_timestamp[i].tv_sec, time2_activation_timestamp[i].tv_nsec/1000000,
    time3_activation_timestamp[i].tv_sec, time3_activation_timestamp[i].tv_nsec/1000000
  );
    write(aux_f, message, strlen(message)-1);
  }
  char f[] = "];\n\n";
  write(aux_f, f, strlen(f));


  close(aux_f);
}


int main(){

  /* Reset all values on the log arrays */
  for(int i=0; i < MatLab_sizes; i++){
    time1_activation_timestamp[i].tv_sec = 0;
    time1_activation_timestamp[i].tv_nsec = 0;
    time1_dt1_timestamp[i].tv_sec = 0;
    time1_dt1_timestamp[i].tv_nsec = 0;
    time1_dt2_timestamp[i].tv_sec = 0;
    time1_dt2_timestamp[i].tv_nsec = 0;

    time2_activation_timestamp[i].tv_sec = 0;
    time2_activation_timestamp[i].tv_nsec = 0;
    time2_dt1_timestamp[i].tv_sec = 0;
    time2_dt1_timestamp[i].tv_nsec = 0;
    time2_dt2_timestamp[i].tv_sec = 0;
    time2_dt2_timestamp[i].tv_nsec = 0;

    time3_activation_timestamp[i].tv_sec = 0;
    time3_activation_timestamp[i].tv_nsec = 0;
    time3_dt1_timestamp[i].tv_sec = 0;
    time3_dt1_timestamp[i].tv_nsec = 0;
    time3_dt2_timestamp[i].tv_sec = 0;
    time3_dt2_timestamp[i].tv_nsec = 0;
  }

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


  /* Set priority switch time */
  switch_dt.tv_sec = 5; switch_dt.tv_nsec = 0;
  clock_gettime(CLOCK_MONOTONIC, &switch_time);
  switch_time = timespec_sum(switch_time, switch_dt);


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

  /* Sleep for 30 seconds and then cancel all threads and dump log values*/
  while(1){

    sleep(30);
    pthread_cancel(thr[0]);
    pthread_cancel(thr[1]);
    pthread_cancel(thr[2]);
    printf("Started saving values\n");
    Dump_MatLab();
    printf("Done saving values\n");
    exit(0);
    //pause();
  }


}
