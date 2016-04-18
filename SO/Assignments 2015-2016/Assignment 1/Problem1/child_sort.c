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

	Function that the child process for "sort" runs
	For more info check "Problem1.h"

===========================================================================*/


#include "Problem1.h"


/*=====================================================================
*	int process_child_sort()
*
*		This will be run by the child process related to the "sort" command
*		This will use the "sort" command, receiving the input from the RD side of the FIFO "pipe_cut_to_sort" 
*	that is connected to the process running "cut".
*		The output of "sort" will be sent to the process running "uniq" using a socket
*
*		This process will be the server side of the socket
*
=====================================================================*/
int process_child_sort(){

	//close both the RD and the WR file decriptor of the pipe - this process won't use them
	close(fd_cat_to_cut[0]);
	close(fd_cat_to_cut[1]);

	/*
		open the created FIFO in read only to receive data
		This is also to get the file descriptor
	*/
	int named_pipe = open(FIFO_PATH, O_RDONLY );
	if(named_pipe < 0){
		printf("Error opening FIFO: %s\n", strerror(errno));
		return(0);
	}

	/* Set stdin to be the named pipe file descriptor and close the orignal named pipe descriptor */
	dup2(named_pipe,0);
	close(named_pipe);

	/*========================================================
	*	Configuration of a socket on the server side
	*
	*	-First call socket() and get the descriptor 
	*	-bind() to have a name for the socket
	*	-listen() to set the socket as passive - to accept incoming connection requests with accept()
	*	-accept() to connect to pending requests or wait until a connection request is made
	*
	*	After that accept() returns a file descriptor where the server can communicate with the client
	*	The stdout is changed to that file descriptor and (sort) is executed
	========================================================*/
	int socket_descriptor = socket(AF_LOCAL, SOCK_STREAM, 0);
	if(socket_descriptor == -1){
		printf("Erro creating socket: %s\n", strerror(errno));
		exit(0);
	}

	/* Declaration of variables */
	struct sockaddr_un myaddr, peer_addr;
	socklen_t peer_addr_size;

	/* To use with bind() - set to the config of socket() and the path for the socket file */
	memset(&myaddr, 0, sizeof(struct sockaddr_un));
	myaddr.sun_family = AF_LOCAL;
	strcpy(myaddr.sun_path, MY_SOCK_PATH);


	/*============================== bind() ============================*/
	if(bind(socket_descriptor, (struct sockaddr *)&myaddr, sizeof(struct sockaddr_un) ) == -1){
		printf("Error binding socket: %s\n", strerror(errno));
		exit(-1);
	}

	/*============================= listen() ============================*/
	if(listen(socket_descriptor, 50) == -1){
			printf("Error listening to socket: %s\n", strerror(errno));
			exit(-1);
	}

	//clear peer_addr 
	peer_addr_size = sizeof(struct sockaddr_un);
	memset(&peer_addr, 0, sizeof(struct sockaddr_un));

	/*============================= accept() ============================*/
	int temp_descriptor = accept(socket_descriptor, (struct sockaddr *)&peer_addr, &peer_addr_size);

	/* Set stdout to be the client file descriptor on the socket and close the original*/
	dup2(temp_descriptor,1);
	close(temp_descriptor);


	/*
		Execute sort
		At this point there should just be 3 file descriptors
		- 0, before was stdin - will be the RD side of the FIFO/Named pipe "pipe_cut_to_sort"
		- 1, before was stdout - will be the file descriptor for a socket returned by "accept"
		- 2, will stay stderror
	*/
	execlp("sort", "sort", NULL);

	//if successfull, execlp should not return, so this will not be executed
	return 0;
}