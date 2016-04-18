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
	     - In the folder with the source code and makefile call "make"
	 to generate the executable.
	     - Call "make play" to run the program.
	     - Try CTRL-Z and CTRL-\ and see no response
	     - Press CTRl-C, see message
	     - Wait more than 3 seconds
	     - Press CTRL-C, see same message again
	     - Press again CTRL-C in less than 3 seconds, see that program
	  terminated


	     -Call "make clean" to erase the objects and executable
	================================

	==================================
	     Functional description:

	      This program will be configured to ignore SIGTSTP (CTRL-Z), block
	  SIGQUIT (CTRL-\) and configures a handler for SIGINT (CTRL-C)
	      The program will sleep forever until CTRL-C is pressed, where it will
	  tell you to press it again to terminate the program. If after 3 seconds
	  you press CTRL-C the program terminates, otherwhise the program "forgets"
	  that CTRL-C was previosly pressed
===============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/* Signal handler for the SIGINT signal (CTRL-C) */
void SIGINT_Handler();

/* Variable that "remembers" or "forgets" if the signal SIGINT has occured in a 3 second spaw*/
int pressed=0;

int main() {

     /* Set CTRL-C signal handler to be SIGINT_Handler*/
     signal(SIGINT, SIGINT_Handler);

     /*
      Use sigprocmask to block SIGQUIT, CTRL-\ signal
     	That requires 2 sigset_t type variables.
     		-orig_mask is just to hold on to the original mask
     		-mask will be used to hold the signal to change. To change sigset_t a function to clear it and another to set it is used.
     */
     sigset_t mask;
     sigset_t orig_mask;
     sigemptyset(&mask);
     sigaddset(&mask,SIGQUIT);
     sigprocmask(SIG_BLOCK, &mask, &orig_mask);


     /* Set SIGTSTP, CTRL-Z to be ignored (not blocked) */
     signal(SIGTSTP, SIG_IGN);



     printf("Interrupt twice with CTRL-C to quit\n");


     while(1){
     	//Sleep until a signal occurs
     	pause();

     	/*==================================================================

               if SIGINT signal occured then sleep for just 3 seconds, after that set pressed to 0 to
     	"forget" that the signal occured before
     		This will also make sure, if another odd signal makes the process get out of pause, it doesn't
     	start the 3 seconds to forget sequence.

     	==================================================================*/
     	if(pressed == 1){

     		/* this is just that, if for some odd reason, another signal
     		 occurs and makes it exit out of sleep, it will only do pressed=0 after 3 seconds for sure */
     		int n = 3;
     		do{
     			n = sleep(n);
     		}while(n!=0);


     		pressed = 0;
     	}
     }

	return(0);
}


/*
     void SIGINT_Handler()

     This is the handler for the SIGINT interrupt
     If pressed = 1 then it will terminate the program (CTRL-C was pressed less than 3 seconds ago)
     If not, it will print a message and set pressed to 1.
*/
void SIGINT_Handler(){

	//if the signal has occured before, exit.
	if(pressed == 1){

		exit(0);
	}
	 /*--------------------------------------
     NOTE some versions of UNIX will reset
     signal to default after each call. So for
     portability reset signal each time */
     //signal(SIGINT, SIGINT_Handler);
     /*------------------------------------*/

     printf("Interrupt again to exit \n");

     //Set pressed to 1 to know that the signal occured before
     pressed = 1;


}
