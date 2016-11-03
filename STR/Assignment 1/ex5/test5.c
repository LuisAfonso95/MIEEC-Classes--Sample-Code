/*=========================================================



"Develop the source code func2.c of a module func2.o that imitates the functioning of the
module func.o."

  This is the same as ex1, only the functions changed to be the ones used in func2.c

  This program runs each function once and prints out the time each took to execute.
  Process for each function:
    - Log current time - dt1
    - Execute functions
    - Log current time - dt2
    - Calculate execution time = dt2-dt1
    - Print execution time
=========================================================*/





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
#include <sched.h>

#include "../common_files/func.h"
#include "../common_files/timespec_math.h"




#define NUMBER_OF_AVERAGES 64


int main(){

  //lock memory
  mlockall(MCL_CURRENT|MCL_FUTURE);

  //Set main process affinity to CPU0
  cpu_set_t my_set;
  CPU_ZERO(&my_set);
  CPU_SET(0, &my_set);
  if(sched_setaffinity(0, sizeof(cpu_set_t), &my_set)){
    printf("Error setting affinity: %s", strerror(errno));
    exit(0);
  }
  /*============================== f1 ============================== */
  struct timespec temp1,temp2, sum = {0,0}, worst_time = {0, 0};
  for(int i = 0; i < NUMBER_OF_AVERAGES; i++){
    clock_gettime(CLOCK_MONOTONIC, &temp1);
    f1(2,3);
    clock_gettime(CLOCK_MONOTONIC, &temp2);
    struct timespec delta_time = timespec_diference(temp2, temp1);

    struct timespec temp = timespec_diference(worst_time, delta_time);
    if(temp.tv_sec <0 || temp.tv_nsec < 0){
      worst_time = delta_time;
    }

    sum = timespec_sum(sum, delta_time);
  }
  struct timespec execution_average = timespec_division_by_int(sum, NUMBER_OF_AVERAGES);

  //print average execution time
  long us = execution_average.tv_nsec/1000 %1000, ms = execution_average.tv_nsec/1000000;
  printf("Function \"f1\" took in average: %ld seconds, %ld milliseconds, %ld microseconds and %ld nanoseconds\n",
        execution_average.tv_sec, ms, us, execution_average.tv_nsec%1000);
  //print worst execution time
  us = worst_time.tv_nsec/1000 %1000, ms = worst_time.tv_nsec/1000000;
  printf("Function f1 worst execution time was:  %ld seconds, %ld milliseconds, %ld microseconds and %ld nanoseconds\n\n",
      worst_time.tv_sec, ms, us, worst_time.tv_nsec%1000);

  /*============================== f2 ============================== */
  sum.tv_sec = 0; sum.tv_nsec = 0;
  worst_time.tv_sec = 0; worst_time.tv_nsec = 0;
  for(int i = 0; i < NUMBER_OF_AVERAGES; i++){
    clock_gettime(CLOCK_MONOTONIC, &temp1);
    f2(2,3);
    clock_gettime(CLOCK_MONOTONIC, &temp2);
    struct timespec delta_time = timespec_diference(temp2, temp1);

    struct timespec temp = timespec_diference(worst_time, delta_time);
    if(temp.tv_sec <0 || temp.tv_nsec < 0){
      worst_time = delta_time;
    }

    sum = timespec_sum(sum, delta_time);
  }
  execution_average = timespec_division_by_int(sum, NUMBER_OF_AVERAGES);

  //print average execution time
  us = execution_average.tv_nsec/1000 %1000;
  ms = execution_average.tv_nsec/1000000;
  printf("Function \"f2\" took in average: %ld seconds, %ld milliseconds, %ld microseconds and %ld nanoseconds\n",
        execution_average.tv_sec, ms, us, execution_average.tv_nsec%1000);
  //print worst execution time
  us = worst_time.tv_nsec/1000 %1000, ms = worst_time.tv_nsec/1000000;
  printf("Function f2 worst execution time was:  %ld seconds, %ld milliseconds, %ld microseconds and %ld nanoseconds\n\n",
      worst_time.tv_sec, ms, us, worst_time.tv_nsec%1000);

  /*============================== f3 ============================== */
  sum.tv_sec = 0; sum.tv_nsec = 0;
  worst_time.tv_sec = 0; worst_time.tv_nsec = 0;
  for(int i = 0; i < NUMBER_OF_AVERAGES; i++){
    clock_gettime(CLOCK_MONOTONIC, &temp1);
    f3(2,3);
    clock_gettime(CLOCK_MONOTONIC, &temp2);
    struct timespec delta_time = timespec_diference(temp2, temp1);

    struct timespec temp = timespec_diference(worst_time, delta_time);
    if(temp.tv_sec <0 || temp.tv_nsec < 0){
      worst_time = delta_time;
    }

    sum = timespec_sum(sum, delta_time);
  }
  execution_average = timespec_division_by_int(sum, NUMBER_OF_AVERAGES);

  //print average execution time
  us = execution_average.tv_nsec/1000 %1000;
  ms = execution_average.tv_nsec/1000000;
  printf("Function \"f3\" took in average: %ld seconds, %ld milliseconds, %ld microseconds and %ld nanoseconds\n",
        execution_average.tv_sec, ms, us, execution_average.tv_nsec%1000);
  //print worst execution time
  us = worst_time.tv_nsec/1000 %1000, ms = worst_time.tv_nsec/1000000;
  printf("Function f3 worst execution time was:  %ld seconds, %ld milliseconds, %ld microseconds and %ld nanoseconds\n\n",
      worst_time.tv_sec, ms, us, worst_time.tv_nsec%1000);


}
