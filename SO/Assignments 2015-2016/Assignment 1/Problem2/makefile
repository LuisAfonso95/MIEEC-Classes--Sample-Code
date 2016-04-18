
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
#   Makefile for the Problem 2 of the 1st pratical assignment of SO 2015/2016
#

#====Variables====
CC = gcc
OBJS = Problem2.o
PROG = Problem2

#Call "make" with any of these labels in front to execute (default will be all)
all:	${PROG}

#removes the program and the objects that are created from compiling the program
clean:
		rm ${OBJS} ${PROG}

#clears the console then runs the program
play:
		clear
		./${PROG}


#=====Compilation======
${PROG}:	${OBJS}
			${CC} -Wall ${OBJS} -o ${PROG}


Problem2.o: Problem2.c
	${CC} -Wall -c Problem2.c
