#ifndef PROBLEM2_H_
#define PROBLEM2_H_


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <semaphore.h>
#include <pthread.h>
#include <string.h>
#include <mqueue.h>


#define QUEUE_NAME  "/test_queue"
#define MAX_BYTES 10
#define MSG_STOP    "exit"
#define MESSAGE_KEY 0x1112

typedef struct {

	long mtype;
	char mtext[MAX_BYTES];

}msg_buf;


#endif /* #ifndef PROBLEM2_H_ */