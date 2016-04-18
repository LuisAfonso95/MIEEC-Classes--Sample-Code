
# +-----------------------------------------------+----------------------------+
# |            Universidade de Coimbra            |         Abr - 2016         |
# +-----------------------------------------------+----------------------------+
# |                         Sistemas Operativos - MIEEC                        |
# +----------------------------------------------------------------------------+
# | Processes, Files, Pipes, FIFOs, I/O Redirection, Unix Sockets, and Signals |
# +----------------------------------------------------------------------------+
# |                                Grupo 5 - TP3                               |
# +----------------------------------------------------------------------------+
# | Cristiano André Ramos Alves                   | 2009109526                 |
# +-----------------------------------------------+----------------------------+
# | Luís Rafael dos Santos Afonso                 | 2013135191                 |
# +-----------------------------------------------+----------------------------+
#
#	Makefile for the Problem 4 of the 1st pratical assignment of SO 2015/2016
#

#====Variables====
CC = gcc
OBJS = Problem4.o
PROG = Problem4
FILES = problem4_file.txt

#Call "make" with any of these labels in front to execute (default will be all)
all:	${PROG}

#removes the program and the objects and files that are created from compiling and executing the program
clean:
		rm ${OBJS} ${PROG} ${FILES}

#clears the console then runs the program
play:
		clear
		./${PROG}


#=====Compilation======
${PROG}:	${OBJS}
			${CC} -Wall ${OBJS} -o ${PROG}


Problem4.o: Problem4.c
	${CC} -Wall -c Problem4.c
