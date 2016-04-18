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
 
	Function that the child process for "cat" runs
	For more info check "Problem1.h"

===========================================================================*/


#include "Problem1.h"


/*=====================================================================
*	int process_child_cat()
*
*		This will be run by the child process related to the "cat" command
*		This will use the "cat" command with the arguments ""/etc/passwd", "/etc/passwd"" and put the output
*	in the WR of the pipe fd_cat_to_cut - sending it to the "cut" process
*
=====================================================================*/
int process_child_cat(){
	/* Closing the RD descriptor of the pipe (we are gonna send from this process) */
	close(fd_cat_to_cut[0]);

	dup2(fd_cat_to_cut[1], 1); //set stdout/1 to pipe WR descriptor
	close(fd_cat_to_cut[1]); //close original pipe WR descriptor to just have 3 descriptors


	/*
		Execute cat
		At this point there should just be 3 file descriptors
		- 0, will stay stdin
		- 1, before was stdout - will be the WR side of the pipe fd_cat_to_cut
		- 2, will stay stderror
	*/
	execlp("cat", "cat", "/etc/passwd", "/etc/passwd", NULL);

	//if successfull, execlp should not return, so this will not be executed

	return 0;
}