
#include "timespec_math.h"


/*====================timespec math ================================*/
struct timespec timespec_sum(struct timespec first_time, struct timespec second_time){
  struct timespec time_delta;
  time_delta.tv_sec = second_time.tv_sec + first_time.tv_sec;
  if(first_time.tv_nsec + second_time.tv_nsec > 1000000000){
    time_delta.tv_sec++;
    time_delta.tv_nsec =  first_time.tv_nsec + second_time.tv_nsec - 1000000000;
  }
  else{
    time_delta.tv_nsec = second_time.tv_nsec + first_time.tv_nsec;
  }

  time_delta.tv_nsec += (time_delta.tv_nsec/1000000000);
  time_delta.tv_nsec = time_delta.tv_nsec%1000000000;

  return time_delta;
}
struct timespec timespec_diference(struct timespec second_time, struct timespec first_time){
  struct timespec time_delta;
  time_delta.tv_sec = second_time.tv_sec - first_time.tv_sec;
  if(first_time.tv_nsec > second_time.tv_nsec){
    time_delta.tv_nsec = 1000000000 + second_time.tv_nsec - first_time.tv_nsec;
    time_delta.tv_sec--;
  }
  else{
    time_delta.tv_nsec = second_time.tv_nsec - first_time.tv_nsec;
  }

  return time_delta;
}

int timespec_division_to_int(struct timespec numerator, struct timespec denominator){

  //printf("in calc: %ld; %ld \n", numerator.tv_sec * 1000000000 + numerator.tv_nsec, denominator.tv_sec * 1000000000 + denominator.tv_nsec);
  int n = (numerator.tv_sec * 1000000000 + numerator.tv_nsec) /
  (denominator.tv_sec * 1000000000 + denominator.tv_nsec);
  return n;

}

struct timespec timespec_mult_by_int(struct timespec time, int n){
  struct timespec result;
  result.tv_nsec = time.tv_nsec * n ;
  result.tv_sec = (time.tv_sec * n) + (result.tv_nsec /1000000000);
  result.tv_nsec = result.tv_nsec % 1000000000;

  return result;
}

struct timespec timespec_division_by_int(struct timespec numerator, int n){
  struct timespec result;
  long r = numerator.tv_sec * 1000000000 + numerator.tv_nsec;
  r = r / n;

  result.tv_sec = r / 1000000000;
  result.tv_nsec = r % 1000000000;

  return result;

}
