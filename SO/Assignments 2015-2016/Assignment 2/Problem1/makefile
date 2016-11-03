
#====Variables====
CC = gcc
HEADER = 
OBJS = tpso1602.o 
PROG = tpso1602
FILES = 

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
			${CC}  -pthread  ${OBJS}  -Wall  -o  ${PROG} -lrt


tpso1602.o: tpso1602.c
	${CC} -Wall -c tpso1602.c

