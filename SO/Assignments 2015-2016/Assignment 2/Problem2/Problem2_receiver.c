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

	Problem 2 - receiver program

	This is to be used in conjuction with program with source code Problem2_sender.c

		================================
		How to use:
			- open a terminal in Problem2 folder
			- to compile do "make" and it will compile both the sender and receiver programs
			- run this program with: "./receiver file_out.txt". file_out.txt can have any name 
		and it's where the received message will be stored. 
			- now run the sender program.
			- It should print in the console a success message and you should see the output on the specified file name



	================================


*/



#include "Problem2.h"

#define timeout_seconds 5

int main (int argc, char *argv[]) {

	/* Check if there are only 2 arguments */
	if(argc != 2){
		
		if(argc > 2)
			printf("Error: Too many arguments\n");
		else
			printf("Error: Not enough arguments\n");

		printf("Example: ./receiver file_out.txt\n");

		return 0;
	}


	
	int aux_f = open(argv[1],  O_CREAT|O_EXCL|O_WRONLY, (S_IRUSR | S_IWUSR)); // Also creates the file
	if(  aux_f == -1){
		//error
		printf("Error: %s\n", strerror(errno));
		exit(0);
	}

	/* Request a key creation  for the message queue - will not create if one already exists */
	
	int msgqid = msgget(MESSAGE_KEY, IPC_CREAT|IPC_EXCL|0777);
	if(msgqid == -1){
		close(aux_f);
		printf("Error: %s\n", strerror(errno));
		exit(0);	
	}

	/* Set maximum number of bytes on queue to MAX_BYTES*/
	struct msqid_ds control;
	msgctl(msgqid, IPC_STAT,&control);
	control.msg_qbytes = MAX_BYTES;
	msgctl(msgqid, IPC_SET,&control);

	/* Create message struct buffer*/
	msg_buf message;
	message.mtype = 1;



	ssize_t bytes_read = 0; //holds return value of msgrcv()
	int Total_Packets=0; //total number of messages to be received
	int packet_number = 0; //number of last packet received
	unsigned int numberBytes =0; //number of bytes remaining to receive
	printf("\nThe process will now wait %d seconds for communication\n\n",timeout_seconds);

	do{
	

	    /* Wait for a message. Waits until a timeout occurs */
	    int t =0;
	    bytes_read = -1;
	    while( (t < timeout_seconds* 100) && (bytes_read == -1)){
	 	   bytes_read = msgrcv(msgqid, &message, sizeof(message.mtext),0, IPC_NOWAIT); //should always return MAX_BYTES the way the sender is made.
	 	   t++;
	 	   usleep(10000);
	 	}


	    /* 
	    	Checks if there we're bytes received and writes them into the output file.
	    	If it's the first packet received, then it will instead interpret the number as the number of total bytes
	   	that will compose the file received.
	    */
	    if(bytes_read >= 0){
	    	packet_number++;
	    	if(packet_number == 1){
	    		
	    		//packet_number;
	    		numberBytes = 0;
	    		for(int i = bytes_read-1; i >=0	; i--){
	    			numberBytes = numberBytes << 8;
	    			numberBytes |= (unsigned char)(message.mtext[i]);
	    			//printf("Number of bytes %X\n", numberBytes); //debug purposes
	    		}

	    		Total_Packets = (unsigned int)(numberBytes / MAX_BYTES); //convert total number of bytes to total number of packets (depends on MAX_BYTES)
	    		if(numberBytes % MAX_BYTES == 0)
	    			Total_Packets--;
	    		printf("Number of bytes to receive %d; total packets %d;\n", numberBytes, Total_Packets+1); //debug purposes
	    	}
	    	else{

	    		if(numberBytes > MAX_BYTES){
	    			write(aux_f, message.mtext, MAX_BYTES);
	    			numberBytes = numberBytes - MAX_BYTES;
	    		}
	    		else{
	    			write(aux_f, message.mtext, numberBytes);
	    		}
	    		
	    		printf("Receiver: Received packet %d\n", packet_number-1); //for debug purposes
		    
	    	}
		}
	}while(packet_number-1 <= Total_Packets && bytes_read != -1);
    
    if(bytes_read == -1 && packet_number-1<= Total_Packets){
    	printf("\nThere was a timeout and the file was not fully received. Output file erased\n\n");
    	close(aux_f);
    	remove(argv[1]);

    }
    else{
    	printf("\nReceiver: file reception and saving is now complete.\n\n");
    	close(aux_f);
    }
	

    /* Remove the message queue */
	if(msgctl(msgqid, IPC_RMID, NULL) == -1){
		//error
		printf("Error: %s\n", strerror(errno));
		exit(0);
	}
	


}