
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
#   Makefile for the Problem 1 of the 1st pratical assignment of SO 2015/2016
#

#====Variables====
CC = gcc
HEADER = Problem1.h
OBJS = Problem1.o child_cat.o child_cut.o child_sort.o child_uniq.o
PROG = Problem1
FILES = file.txt 

#Call "make" with any of these labels in front to execute (default will be all)
all:	${PROG}

#removes the program, the objects and the files that are created from running the program
clean:
		rm ${OBJS} ${PROG} ${FILES}

#clears the console then runs the program
play:
		clear
		./${PROG} 


#=====Compilation======
${PROG}:	${OBJS}
			${CC} -Wall ${HEADER} ${OBJS} -o ${PROG}


Problem1.o: Problem1.c
	${CC} -Wall -c Problem1.c

child_cat.o: child_cat.c
	${CC} -Wall -c child_cat.c

child_cut.o: child_cut.c
	${CC} -Wall -c child_cut.c

child_sort.o: child_sort.c
	${CC} -Wall -c child_sort.c

child_uniq.o: child_uniq.c
	${CC} -Wall -c child_uniq.c