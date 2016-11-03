#include "timespec_math.h"

void rt_task_make_periodic();
void rt_task_make_periodic_relative_ns();
int rt_give_last_activation(struct timespec *wake_time);
int rt_task_wait_period();
