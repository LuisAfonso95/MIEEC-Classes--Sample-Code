/*
 +-----------------------------------------------+----------------------------+
 |            Universidade de Coimbra            |         May - 2016         |
 +-----------------------------------------------+----------------------------+
 |                         Sistemas Operativos - MIEEC                        |
 +----------------------------------------------------------------------------+
 | Inter-Process Communication: Semaphores, Shared Memory, Message Queues;	  |
 | Threads																	  |
 +----------------------------------------------------------------------------+
 |                                Grupo 5 - TP3                               |
 +----------------------------------------------------------------------------+
 | Cristiano André Ramos Alves                   | 2009109526                 |
 +-----------------------------------------------+----------------------------+
 | Luís Rafael dos Santos Afonso                 | 2013135191                 |
 +-----------------------------------------------+----------------------------+

	Problem 2 - sender program

	This is to be used in conjuction with program with source code Problem2_receiver.c

		================================
		How to use:
			- open a terminal in Problem2 folder
			- to compile do "make" and it will compile both the sender and receiver programs
			- first run the "receiver" program which should wait a few seconds for a communication
			- run the "sender" like so: "./sender file_in.txt". file_in.txt can be any file and it must exist.
		The content of file_in.txt will be the message sent.
			- A success message should be printed in the console if no errors occur.



	================================


*/



#include "Problem2.h"

// defines the timeout for "mq_timedreceive"
#define timeout_seconds 5

int Total_Packets=0;

int main (int argc, char *argv[]) {


	/* Check if there are only 2 arguments */
	if(argc != 2){		
		if(argc > 2)
			printf("Error: Too many arguments\n");
		else
			printf("Error: Not enough arguments\n");

		printf("Example: ./sender file_in.txt\n");

		return 0;
	}



	/* Open the file specified by the argument */
	int aux_f = open((char*)argv[1],  O_RDONLY, S_IRUSR | S_IWUSR); // Also creates the file
	if(  aux_f == -1){
		//error
		printf("Error opening the file: %s\n", strerror(errno));
		exit(0);
	}	

	/* Check the size of the file */
	int size = lseek(aux_f, 0, SEEK_END);
	//Go back to the beggining
	lseek(aux_f, 0, SEEK_SET);

	int msgqid = msgget(MESSAGE_KEY, 0);
	if(msgqid == -1){
		close(aux_f);
		printf("Error: %s\n", strerror(errno));
		exit(0);	
	}

	/* Set maximum number of bytes on queue to MAX_BYTES */
	struct msqid_ds control;
	msgctl(msgqid, IPC_STAT,&control);
	control.msg_qbytes = MAX_BYTES;
	msgctl(msgqid, IPC_SET,&control);


	/* Buffer struct that will hold the message */
	msg_buf message;

	/*
		 Send the total number of bytes to be sent.
		 This is done by using the 8 bit array (well it's a string).
		 The number will be represented by a concatenation of each byte.
		 Index 0 will be the least significant byte

		 Ex: size = 0x67F536
		 numberBytes[0] = 0x36;
		 numberBytes[1] = 0xF5;
		 numberBytes[2] = 0x67;

		 Because the way it is implemented, if the size is bigger than 2^(8*MAX_BYTES), the program will not work
		 properly

	*/

	int k=0;
	int size_temp = size;
	while(size_temp != 0){		
		message.mtext[k] = (size_temp);
		size_temp = size_temp >> 8;
		k++;
	}
	while(k < MAX_BYTES){ //set all the other bytes to 0
		message.mtext[k] = 0;
		k++;
	}
	Total_Packets = (size / MAX_BYTES) + 1;
	msgsnd(msgqid, &message, sizeof(message.mtext), 0);
	
	//printf("size: %d, Number of Packets %d\n", size, Total_Packets); //for debug purposes


	/* Read the file MAX_BYTES at a time and send them as a message to the receiver */
	printf("\nReading input file and sending... please wait\n");
	for(int i=0; i < size; i+=MAX_BYTES){
		lseek(aux_f, i, SEEK_SET);

		if(i + MAX_BYTES-1 > size){
			read(aux_f, message.mtext, size - i);
			msgsnd(msgqid, &message, sizeof(message.mtext), 0);
		}
		else{
			read(aux_f, message.mtext, MAX_BYTES);
			msgsnd(msgqid, &message, sizeof(message.mtext), 0);
		}
	}

	printf("\nSender: file reading and sending is now complete.\n\n");

    close(aux_f);
}