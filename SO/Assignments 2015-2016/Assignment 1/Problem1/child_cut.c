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

	Function that the child process for "cut" runs
	For more info check "Problem1.h"

===========================================================================*/


#include "Problem1.h"


/*=====================================================================
*	int process_child_cut()
*
*		This will be run by the child process related to the "cat" command
*		This will use the "cut" command, receiving the input from the RD side of the pipe "fd_cat_to_cut" 
*	that is connected to the process running "cat".
*		The output of "cut" will go to the WR of the FIFO "pipe_cut_to_sort", connected to the process
*	that runs the "sort" command
*
=====================================================================*/
int process_child_cut(){

	/* Closing the WR descriptor of the pipe (we are gonna receive from this process) */
	close(fd_cat_to_cut[1]);

	dup2(fd_cat_to_cut[0], 0); //set stdin/0 to pipe RD descriptor
	close(fd_cat_to_cut[0]); //close original pipe RD descriptor to just have 3 descriptors


	/*
		open the created FIFO in write only to send data
		This is also to get the file descriptor
	*/
	int named_pipe = open(FIFO_PATH, O_WRONLY);
	if(named_pipe == -1){
		exit (0);
	}

	//Change stdout to the file descriptor of the FIFO and close the original descriptor
	dup2(named_pipe,1);
	close(named_pipe);

	/*
		Execute cut
		At this point there should just be 3 file descriptors
		- 0, before was stdin - will be the RD side of the pipe fd_cat_to_cut
		- 1, before was stdout - will be the WR side of the FIFO/Named pipe "pipe_cut_to_sort"
		- 2, will stay stderror
	*/
	execlp("cut", "cut", "-d", ":", "-f", "1", NULL);

	//if successfull, execlp should not return, so this will not be executed

	return 0;
}
