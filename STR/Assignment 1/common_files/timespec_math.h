

#include <time.h>



/*====================timespec math ================================*/
struct timespec timespec_sum(struct timespec first_time, struct timespec second_time);
struct timespec timespec_diference(struct timespec second_time, struct timespec first_time);
struct timespec timespec_mult_by_int(struct timespec time, int n);
int timespec_division_to_int(struct timespec numerator, struct timespec denominator);
struct timespec timespec_division_by_int(struct timespec numerator, int n);
