/*-----------------------------------------------------------------------*/
/*                  tpso1602.c                                           */
/*-----------------------------------------------------------------------*/
/*  Compilation: make                                                    */
/*-----------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <pthread.h>
#include <string.h>
       

/*-----------------------------------------------------------------------*/
/*                  macro definitions                                    */
/*-----------------------------------------------------------------------*/
#define NUM_WRITERS 22
#define NUM_READERS 20
#define LIST_SIZE 500

#define SHARED_MEM_PATH "myregion"

/*-----------------------------------------------------------------------*/
/*                  type definitions                                     */
/*-----------------------------------------------------------------------*/
typedef struct{
  sem_t mutex;
  sem_t stop_writers;
  int tail;
  int head;
  int readers;
  int slots[LIST_SIZE];
} mem_structure;

/*
	This struct is used for both the reader threads and writter threads.
	It allows to pass 2 arguments, the address to the shared memory and the self number of the thread
*/
typedef struct{
	mem_structure *queue;
	int my_Number;
}thread_arg;

/*-----------------------------------------------------------------------*/
/*                  global variables definitions                         */
/*-----------------------------------------------------------------------*/
int POTW_PID; //PID for the process off the writters
int POTR_PID; //PID for the process off the readers

//Global pointer so that the handler "cleanup" knows where the shared memory is
mem_structure *qeueu_global;


/*-----------------------------------------------------------------------*/
/*                  cleanup()                                            */
/*-----------------------------------------------------------------------*/
void cleanup(int signo){

  /*insert here code to terminate the POTW and POTR, and to wait for their termination*/

  //should not be needed since the childs have the default SIGINT handler which terminates them
  kill(POTW_PID, SIGQUIT);
  kill(POTR_PID, SIGQUIT);

  //Wait for the child processes to finish.
  int status;
  waitpid(POTW_PID, &status, 0);
  waitpid(POTR_PID, &status, 0);   

  /*insert here code to unmap and remove the shared memory area, and to destroy the semaphores*/

  //is this really necessary? This should be the only process by now that has it mapped so when it ends it will automatically unmap
  if(munmap(qeueu_global, sizeof(mem_structure)) == -1)
  	printf("Errro: %s\n", strerror(errno));

  //If there are other process with it mapped then it will not actually remove the memory content
  if( shm_unlink(SHARED_MEM_PATH) == -1)
  	printf("Error: %s\n", strerror(errno));
  
  //the only advantage I see of this is: if for some really odd reason a thread is still running and is blocked, it will unblock.
  if(sem_destroy( &(qeueu_global->mutex)) == -1)
  	printf("Error: %s\n", strerror(errno));
  if(sem_destroy( &(qeueu_global->stop_writers)) == -1)
 	 printf("Error: %s\n", strerror(errno));


  printf("\nBye, bye\n");
  exit(0);
}


/*-----------------------------------------------------------------------*/
/*                  next()                                               */
/*-----------------------------------------------------------------------*/
int next(int pos){

  return (pos + 1) % LIST_SIZE;  
}

/*-----------------------------------------------------------------------*/
/*                  get_code()                                           */
/*-----------------------------------------------------------------------*/
int get_code(){

  return 1 + (int) ( random() % 1000 );
}

/*-----------------------------------------------------------------------*/
/*                  do_write()                                           */
/*-----------------------------------------------------------------------*/
void do_write(int n_writer, mem_structure *queue){

  queue->slots[queue->head] = get_code();
  fprintf(stderr, "CENTRAL: %d received call %d at position %d.\n", 
          n_writer, queue->slots[queue->head], queue->head);
  queue->head = next(queue->head);
}

/*-----------------------------------------------------------------------*/
/*                  writer()                                             */
/*-----------------------------------------------------------------------*/

void* Writers_Threads(void* arg){
	thread_arg *arguments = (thread_arg *)arg;
	mem_structure *queue = arguments->queue;
	int my_Number =  arguments->my_Number;

	while(1){

		sleep(random()%11);
		sem_wait(&(queue->stop_writers));

		do_write(my_Number, queue);
		//pause(); //testing purposes. Central should just receive 1 single call and the operators should still all be working (and will only answer the 1 call). Other write threads could be unlocked if there are no readers, since that means the readers thread will unlock the writers semaphore 
		sem_post(&(queue->stop_writers));
		
		
		
	}
}

/*-----------------------------------------------------------------------*/
/*                  do_read()                                            */
/*-----------------------------------------------------------------------*/
void do_read(int pos, int n_reader, mem_structure *queue){

  if (pos != queue->head)
    fprintf(stderr, "OPERATOR %d answered call %d from position %d.\n", 
            n_reader, queue->slots[pos], pos);
  else
    fprintf(stderr, "OPERADOR %d - There are no calls.\n", n_reader);
}

/*-----------------------------------------------------------------------*/
/*                  reader()                                             */
/*-----------------------------------------------------------------------*/
void* Readers_Threads(void* arg){

	thread_arg *arguments = (thread_arg *)arg;
	mem_structure *queue = arguments->queue;
	int my_Number =  arguments->my_Number;

	while(1){

		sleep(random()%11);

		sem_wait(&queue->mutex);
		int local_tail = queue->tail;
		(queue->readers)++;

		if(queue->tail !=  queue->head)
			 queue->tail = next(queue->tail);

		//pause(); //testing purposes. No operator should print out, but all the centrals should still work
		if(queue->readers == 1)
			sem_trywait(&queue->stop_writers);

		sem_post(&queue->mutex);
		do_read(local_tail, my_Number, queue);
		sem_wait(&queue->mutex);
		(queue->readers)--;


		if((queue->readers) == 0)
			sem_post(&queue->stop_writers);

		
	
		sem_post(&queue->mutex);


		
		
	}
}

/*-----------------------------------------------------------------------*/
/*                  monitor()                                            */
/*-----------------------------------------------------------------------*/
int monitor(mem_structure *queue){

  int aux;
  struct sigaction act;

  act.sa_handler = cleanup;
  act.sa_flags = 0;
  if ((sigemptyset(&act.sa_mask) == -1) || 
    (sigaction(SIGINT, &act, NULL) == -1)) 
    perror("Failed to set SIGINT to handle Ctrl-C.");

  while (1) {

    /*insert here code to make a wait operation on the stop_writers semaphore*/
    sem_wait(&queue->stop_writers);

    aux = queue->tail == queue->head ? 0 : 
          queue->tail  < queue->head ? queue->head - queue->tail : 
                                   LIST_SIZE - (queue->tail - queue->head);
    fprintf(stderr, "\nThere are %d calls waiting.\n\n", aux);

    /*insert here code to make a signal operation on the stop_writers semaphore*/	
	sem_post(&queue->stop_writers);

    sleep(5);
  }
  return(0);
}

/*-----------------------------------------------------------------------*/
/*                  main()                                               */
/*-----------------------------------------------------------------------*/
int main(int argc, char *argv[]){

	//since a global pointer is required for the signal handler, this local variable could be substituted by it.
	mem_structure *queue;

	/*insert here code to create the shared memory area*/

	int shmfd; // shared memory file descriptor
	shmfd = shm_open(SHARED_MEM_PATH, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if(shmfd == -1){
		printf("Error: %s\n", strerror(errno));
		exit(0);
	}
	//Truncate shared memory to the size of the struct mem_structure
	if (ftruncate(shmfd, sizeof( mem_structure)) == -1){
		printf("Error: %s\n", strerror(errno));
		exit(0);
	}


	/* Map shared memory space in the process memory*/
	queue = mmap(NULL, sizeof( mem_structure), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
	if (queue == MAP_FAILED){
		printf("Error: %s\n", strerror(errno));
		exit(0);
	}


/*=== insert here code to create the semaphores ===*/

	queue->tail = 0;
	queue->head = 0;
	queue->readers = 0;


	//Init mutex semaphore with value 1
	if( sem_init(&(queue->mutex), 0, 1) == -1) {
      printf("Error: %s\n", strerror(errno));
      exit(0);	
    }
    //Init stop_writers semaphore with value 1
	if( sem_init(&(queue->stop_writers), 0, 1) == -1) {
      printf("Error: %s\n", strerror(errno));
      exit(0);
    }
	
/*=== insert here code to create the "process of the writers" (POTW), and the writer threads within the POTW ===*/
    POTW_PID = fork(); //create first child process, the POTW
    
    //executes if it's the child
    if(POTW_PID == 0){	
		printf("Entering POTW\n");

    	srandom(getpid());	//start random seed with process PID

		pthread_t thr[NUM_WRITERS]; //to store the threads pointers, not gonna use it but it's required for pthread_create
		thread_arg arg[NUM_WRITERS]; //arguments for the threads

		for(int i = 0; i < NUM_WRITERS; i++){
			arg[i].queue = queue; //give as argument the address of the shared memory
			arg[i].my_Number = i+1; //give as argument the self number of the thread 
			pthread_create(&(thr[i]), NULL, Writers_Threads, &(arg[i]));
		}
	
		//after creating the threads the process will be stuck in a loop doing nothing. The threads will do the work.
		//Process stops after a termination signal is sent or the parent kills it.
		while(1);
    }

  /*insert here code to create the "process of the readers" (POTR), and the reader threads within the POTR*/
  	else{
  		POTR_PID = fork();
  		if(POTR_PID == 0){
  			printf("Entering POTR\n");

			srandom(getpid());	//start random seed with process PID

	 		pthread_t thr[NUM_READERS]; //to store the threads pointers, not gonna use it but it's required for pthread_create
			thread_arg arg[NUM_READERS]; //arguments for the threads
			
			for(int i = 0; i < NUM_READERS; i++){
				arg[i].queue = queue; //give as argument the address of the shared memory
				arg[i].my_Number = i+1; //give as argument the self number of the thread 
				pthread_create(&(thr[i]), NULL, Readers_Threads, &(arg[i]) );
			} 

			//after creating the threads the process will be stuck in a loop doing nothing. The threads will do the work.
			//Process stops after a termination signal is sent or the parent kills it.
			while(1);			
  		}


  		else{
  			qeueu_global = queue;
			monitor(queue);
			exit(0);
  		}
    	
    }




}




/*-----------------------------------------------------------------------*/

