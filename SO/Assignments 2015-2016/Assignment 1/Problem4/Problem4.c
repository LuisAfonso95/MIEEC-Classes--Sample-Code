/*
 +-----------------------------------------------+----------------------------+
 |            Universidade de Coimbra            |         Abr - 2016         |
 +-----------------------------------------------+----------------------------+
 |                         Sistemas Operativos - MIEEC                        |
 +----------------------------------------------------------------------------+
 | Processes, Files, Pipes, FIFOs, I/O Redirection, Unix Sockets, and Signals |
 +----------------------------------------------------------------------------+
 |                                Grupo 5 - TP3                               |
 +----------------------------------------------------------------------------+
 | Cristiano André Ramos Alves                   | 2009109526                 |
 +-----------------------------------------------+----------------------------+
 | Luís Rafael dos Santos Afonso                 | 2013135191                 |
 +-----------------------------------------------+----------------------------+

		================================
			How to use:
				- In the folder with the source code and makefile call "make" to
		generate the executable.
				- Call "make play" to run the program.
				- Introduce any string up to 500 chars
				- See the output on the console - if it was the first time running,
		the .txt should be fresh and just contain that string

				-Repeat the process and see how everything is added to the file. See
		that in the console output and by opening the file.
				-You can write in the file by hand and see that the output on the
		console will output that too.


				-To start fresh call "make clean" to erase the objects, executable and
		the .txt

		================================
			Functional description:

		The code has 2 portions. One showing how to use "write()" and other "read()". Both portions use "lseek()"
		In the first portion, the code accepts a user introduced string, up to 500 characters, and writes it into a file.
		This file is named "problem4_file.txt" and will be created if it does not exist.

		Then it will write a user introduced string on the console on the file, follower by a message saying how many chars
	there are in the file before the new strings we're introduced. This value is obtained using "lseek" by going to the end of file and it returns the offset from
	where it stopped in relation to the beggining.
		The sequence of 2 writes - 1 for the user string, other for the message - show how write increments the offset where
	it is writing automatically to where it stopped writing

		In the second portion the content of the file will be read and printed into the console (not only what you just wrote into it but
	anything that is in the file from previous writtes)

		lseek is used to "navigate" the file, for example, to add the introduced strings to the file and to get the size of the file in bytes.

===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(){

	/*===========================================================================
		Portion to show off write()
	===========================================================================*/
	printf("\n \n===Now here is the test writing to a file \"problem4_file.txt\"===\n");
	/* Ask the user a string to write into the file "problem4_file.txt, adding it after a space to what's in the file (if there is any) */
	printf("Write any string, up to 500 chars, to write into \"problem4_file.txt\"\n");
	char input[500];
	fgets(input,sizeof(input),stdin);
	mode_t fdmode = (S_IRUSR | S_IWUSR); // Permissions of acess at file
	int aux_f = open("problem4_file.txt",  O_CREAT|O_WRONLY, fdmode); // Also creates the file

	//If the file already exists it will go the end to start to write a new string.
	int file_size = lseek(aux_f, 0, SEEK_END);

	if(  aux_f == -1){
		//error
		printf("Error opening the file: %s\n", strerror(errno));
		exit(0);
	}

	/* Bellow a space is introduced before the string. After that is writen, the offset increments so
	there is no need to manualy do that to write the string after the space*/
	//char space = ' ';
	//	write(aux_f,&space, 1);
	//This will write the introduced string into the file (minus the \n)
	write(aux_f, input, strlen(input)-1);

	/*
		This will show how after a write the offset on the file increments till were it finished writting
		It will introduce the message " -Previous size of file: ", give the number of chars on the file before
	introducing the user string and introduce a \n.
	*/
 	char message[50];
	sprintf(message, " - Previous size of file: %d\n", file_size);
	write(aux_f, message, strlen(message));
	close(aux_f);


	/*===========================================================================
		Portion to show off read()
	===========================================================================*/
	printf("\n \n===Now here is the test reading from a file \"problem4_file.txt\"===\n");

	/*Opens "problem4_file.txt" but does not create it*/
	aux_f = open("problem4_file.txt", O_RDWR, fdmode);

	if(  aux_f == -1){
		//error. In case the file does not exist for some reason (since it was created above, it should not happen)
		printf("Error opening the file %s\n", strerror(errno));
		exit(0);
	}

	//Get the size of the file in bytes. lseek returns the offset from the beggining to where it set the offset to operate (in this case it's in the end)
	int size = lseek(aux_f, 0, SEEK_END);

	//Go back to the beggining
	lseek(aux_f, 0, SEEK_SET);

	//Read the whole file into "buffer" and print it.
	char buffer[size];
	read(aux_f, buffer, size);
	printf("%s",buffer);
	close(aux_f);
	return 0;


}
