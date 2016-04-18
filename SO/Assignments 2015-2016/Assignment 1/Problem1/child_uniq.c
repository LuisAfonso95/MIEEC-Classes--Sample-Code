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

	Function that the child process for "uniq" runs
	For more info check "Problem1.h"

===========================================================================*/


#include "Problem1.h"


/*=====================================================================
*	int process_child_uniq()
*
*		This will be run by the child process related to the "uniq" command
*		This will use the "uniq" command, receiving the input from a socket connect to the process running "sort"
*		The output of "uniq" will write to "file.txt"
*
*		This process will be the client side of the socket
*		This process creates the "file.txt" 
*
=====================================================================*/
int process_child_uniq(){

	//close both the RD and the WR file decriptor of the pipe - this process won't use them
	close(fd_cat_to_cut[0]);
	close(fd_cat_to_cut[1]);


	/*========================================================
	*	Configuration of a socket on the client side
	*
	*	-First call socket() and get the descriptor
	*	-Wait 1 second so that the server is configured before connecting 
	*	-Then connect()
	========================================================*/
	int socket_descriptor = socket(AF_LOCAL, SOCK_STREAM, 0);
	if(socket_descriptor == -1){
		printf("Erro creating socket: %s\n", strerror(errno));
		exit(0);
	}

	/* Declaration of variables */
	struct sockaddr_un myaddr;

	/* To use with connect() - set to the config of socket() and the path for the socket file */
	memset(&myaddr, 0, sizeof(struct sockaddr_un));
	myaddr.sun_family = AF_LOCAL;
	strcpy(myaddr.sun_path, MY_SOCK_PATH);

	/* Wait a bit for the server to be configured*/
	sleep(1);

	/*============================= connect() ============================*/
	if(connect(socket_descriptor, (struct sockaddr *)&myaddr, sizeof(struct sockaddr_un)) == -1){
		printf("Error connecting to socket: %s\n", strerror(errno));
		exit(-1);
	}

	/* Set stdin to be the socket file descriptor and close the original*/
	dup2(socket_descriptor,0);
	close(socket_descriptor);

	/* Create the file where the output will be store*/
	int file = open("file.txt", O_CREAT|O_RDWR, (S_IRUSR | S_IWUSR));

	/* Change stdout to the file descriptor of "file.txt" */
	dup2(file,1);
	close(file);

	/*
		Execute uniq
		At this point there should just be 3 file descriptors
		- 0, before was stdin - will be the file descriptor of the socket
		- 1, before was stdout - will be the file descriptor of the file "file.txt"
		- 2, will stay stderror
	*/
	execlp("uniq", "uniq", NULL);

	//if successfull, execlp should not return, so this will not be executed
	return 0;
}
