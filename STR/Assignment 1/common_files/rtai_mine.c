
#include "rtai_mine.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>


sem_t writting_sem;

typedef struct{
  pthread_t thread;
  struct timespec start_time;
  struct timespec period;
  unsigned long n;
}rtai_node;

typedef struct _list_rtai{
  rtai_node data;
  struct _list_rtai *next_rtai_node;
}list_rtai;


list_rtai *list1=NULL;
void _rt_add(pthread_t *_thread, struct timespec _start_time, struct timespec _period){

  list_rtai *temp_list = list1;
  if(list1 == NULL){
    sem_init(&(writting_sem), 0, 1);
    sem_wait(&writting_sem);
    list1 = (list_rtai*)malloc(sizeof(list_rtai));
    list1->next_rtai_node = NULL;
    temp_list = list1;
  }
  else{
    while(temp_list->next_rtai_node != NULL){
      temp_list = temp_list->next_rtai_node;
    }
    sem_wait(&writting_sem);
    temp_list->next_rtai_node = (list_rtai*)malloc(sizeof(list_rtai));
    temp_list = temp_list->next_rtai_node;
  }



  temp_list->data.n = 0;
  temp_list->data.thread = *_thread;
  temp_list->data.start_time = _start_time;
  temp_list->data.period = _period;

  //printf("thread: %lu; start_time_ns: %lu, _period_ns: %lu\n",
  //temp_list->data.thread, temp_list->data.start_time.tv_nsec, temp_list->data.period.tv_nsec);
  sem_post(&writting_sem);
}

int _rt_find_element(pthread_t *_thread, list_rtai **_return){

  list_rtai *temp_list = list1;
  while(temp_list != NULL){

    if(temp_list->data.thread == *_thread){
      *_return = temp_list;
      return 0;
    }

    temp_list = temp_list->next_rtai_node;
  }

  return -1;
}




/*========================== rtai functions ===========================================*/
void rt_task_make_periodic(pthread_t *_thread, struct timespec _start_time, struct timespec _period){
  _rt_add(_thread, _start_time, _period);

}


void rt_task_make_periodic_relative_ns(pthread_t *_thread, struct timespec _start_delay, struct timespec _period){

  struct timespec current_time;
  clock_gettime(CLOCK_MONOTONIC, &current_time);
  //printf("current time: %lus and %ldns\n", current_time.tv_sec, current_time.tv_nsec);
  //_start_delay.tv_sec = 0; //ignore anything that is not in the nsec?
  _rt_add(_thread, timespec_sum(current_time,_start_delay), _period);

}

int rt_give_last_activation(struct timespec *wake_time){
  pthread_t _thread  = pthread_self();
  list_rtai* element = NULL;
  if(_rt_find_element(&_thread, &element) == 0){
    if(element->data.n == 0){
      wake_time->tv_nsec = 0;
      wake_time->tv_sec = 0;
      return 0;
    }

    struct timespec dt = {0, 0};
    if(element->data.n > 1)
      dt = timespec_mult_by_int(element->data.period, element->data.n-1);

    *wake_time = timespec_sum(element->data.start_time, dt);

    return 0;
  }
  else{
    printf("rt_task_wait_period. Error\n");
    return -1;
  }

}


int rt_task_wait_period(){

  pthread_t _thread  = pthread_self();
  list_rtai* element = NULL;
  if(_rt_find_element(&_thread, &element) == 0){

    //struct timespec current_time, since_start;
    //clock_gettime(CLOCK_MONOTONIC, &current_time);

    //since_start = timespec_diference( current_time, element->data.start_time);
    //int n = timespec_division_to_int(since_start, element->data.period);

    struct timespec wake_time, dt;
    //dt = timespec_mult_by_int(element->data.period, n+1);
    dt = timespec_mult_by_int(element->data.period, element->data.n);
    sem_wait(&writting_sem);
    element->data.n++;
    sem_post(&writting_sem);
    wake_time = timespec_sum(element->data.start_time, dt);

    clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &wake_time, NULL);
    return 0;
  }
  else{
    //printf("rt_task_wait_period. Error\n");
    return -1;
  }

}
