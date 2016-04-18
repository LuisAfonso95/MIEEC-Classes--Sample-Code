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

	======================
		Files:
			Problem1.c 				-> main(), parent only runs here, runs "less"
			child_cat.c 			-> child_cat() function, runs "cat"
			child_cut.c				-> child_cutt() function, runs "cut"
			child_sort.c			-> child_sort() function, runs "sort"
			child_uniq.c			-> child_uniq() function, runs "uniq"

		Reason: I don't like scrolling and find dividing codes into files a good
way to organize them when they start to get bigger.
	======================

    ================================
     How to use:
       - In the folder with the source code and makefile call "make" to generate
    the executable.
       - Call "make play" to run the program.
       - See output in console by "less", press q to exit
       - Open "files.txt" and see the output
       - "less" output and "file.txt" should be the same, be in alphabetic
    order and have just 1 kinda short word per line ()


       -Call "make clean" to erase the objects, executable and the .txt
   ================================
       
	  =========================
		Funtional description:

	This code will emulate the following console command:
	“cat /etc/passwd /etc/passwd | cut -d: -f 1 | sort | uniq >file.txt ; less <file.txt”.

	Except 2 of the 3 pipes will not be pipes.
	Between cat and cut a pipe will be used
	Between cut and sort a FIFO will be used
	Between sort and uniq a local socket will be used

	The code will create 4 child process which will tend to "cat", "cut", "sort" and "uniq"
	The parent will take care of "less" after the childs end.

	The pipe and FIFO are created in the beggining by the parent before forking
	The process running "cat" will use the WR of the pipe as stdout
	The process running "cut" will use the RD of the pipe as stdin and the WR of the FIFO as stdout
	The process running "sort" will use the RD of the FIFO as stdin, create a server socket and use the client connection as stdout
	The process running "uniq" will create a client socket and use it as stfin, then it creates a "file.txt" and use it as stdout

	Each child closes any uneccessary file descriptors so that they have only 3 when they run the commands

===========================================================================*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/un.h>

//Path for the socket name to be used with bind and connect
#define MY_SOCK_PATH "t"
#define FIFO_PATH "FIFO_cut_to_sort"
/*
	Each function will be run by a child
*/
int process_child_cat();
int process_child_cut();
int process_child_sort();
int process_child_uniq();


/* File descriptor array for the pipe from cat to cut*/
int fd_cat_to_cut[2];
