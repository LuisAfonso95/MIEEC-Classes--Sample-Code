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

	This is just the header.
	For more info check "Problem1.h"

===========================================================================*/


#include "Problem1.h"


int main(){

	/*
		Variables to hold each child pid
	*/
	int child_cat = -2;
	int child_cut = -2;
	int child_sort = -2;
	int child_uniq = -2;

	/*========================================================
	*
	*	Creation of pipes and FIFOs
	*
	========================================================*/
	/*
		Create a pipe that will be used child_cat to child_cut
	*/
	if(pipe(fd_cat_to_cut) == -1){
		printf("Error creating the pipe: %s\n", strerror(errno));
		exit(0);
	}

	/*
		Create FIFO named FIFO_PATH
	*/
	if(mkfifo(FIFO_PATH, 0777) == -1){
		printf("Error making FIFO: %s\n", strerror(errno));
		exit(0);
	}


	/*========================================================
	*	Create the 4 childs
	*
	*	This is a it convuluted but the idea is:
	*	The parent creates child_cat
	*	If we are in the parent (child_cat != 0), create child_cut
	*	If we are in the parent (child_cut != 0), create child_sort
	*	If we are in the parent (child_sort != 0), create child_uniq
	*
	*	This so that only the parent forks and a total of 4 childs are created.
	========================================================*/
	//Create child for cat process
	child_cat = fork();
	if(child_cat == -1){
		printf("Error creating child for cat: %s\n", strerror(errno));
		exit(0);
	}
	else if(child_cat != 0) //only in the parent, child_cat != 0
		child_cut = fork();

	if(child_cut == -1){
		printf("Error creating child for cut: %s\n", strerror(errno));
		exit(0);
	}
	else if(child_cut != 0) //only in the parent, child_cut != 0
		child_sort = fork();

	if(child_sort == -1){
			printf("Error creating child for sort: %s\n", strerror(errno));
			exit(0);
	}
	else if(child_sort != 0) //only in the parent, child_sort != 0
		child_uniq = fork();

	if(child_uniq == -1){
		printf("Error creating child for uniq: %s\n", strerror(errno));
		exit(0);
	}

	/*========================================================
	*
	*		All processes running bellow (the main part)
	*
	*		Each child has a function where it runs.
	*		The parent is at the end
	*
	========================================================*/

	/* Here is the "cat" process */
	if(child_cat == 0){
		process_child_cat();
	}
	/* Here is the "cut" process */
	else if(child_cut == 0){
		process_child_cut();
	}
	/* Here is the "sort" process */
	else if(child_sort == 0){
		process_child_sort();
	}
	/* Here is the "uniq" process */
	else if(child_uniq == 0){
		process_child_uniq();
	}
	/* Here is the "less" process done by the parent */
	else{

		/* Close all unnecessary file descriptors - in this case just both ends of the pipe fd_cat_to_cut*/
		close(fd_cat_to_cut[0]);
		close(fd_cat_to_cut[1]);

		/* wait for "uniq" child to finish	*/
		int status;
		waitpid(child_uniq, &status, 0);

		/*
		 		unlink the named pipe and the socket created in "bind" so that they are erased,
			even if a error occurs. This way the user won't have to erase them by hand.
		*/
		unlink(FIFO_PATH);
		unlink(MY_SOCK_PATH);

		/* If uniq doesn't return okay then don't run lseek */
		if(status != 0)
			exit(0);

		/* If it's all good to go, put the "file.txt" descriptor in stdin and run less */
		int file = open("file.txt", O_RDWR, S_IRUSR | S_IWUSR); //O_RDWR because weirdly it would not let me open when the make file executes the program
		dup2(file,0);
		close(file);
		execlp("less", "less", NULL);
	}

	exit(0);
}











/*
		Was used to re-atemp connect - would not work with refused connection
*/
/*
		int temp;
		do{
			temp = connect(socket_descriptor, (struct sockaddr *)&myaddr, sizeof(struct sockaddr_un));
			if( errno == ENOENT){
				close(socket_descriptor);
				socket_descriptor = socket(AF_LOCAL, SOCK_STREAM, 0);
				if(socket_descriptor == -1){
					printf("Error creating socket: %s\n", strerror(errno));
					exit(-1);
				}
			}
			else if(temp == -1){
				printf("Error connecting to socket: %s\n", strerror(errno));
				exit(-1);
			}
		}while(errno == ENOENT);
*/
