
#====Variables====
EXTERNAL_DIR=../common_files
CC = gcc
HEADER = ${EXTERNAL_DIR}/func.h ${EXTERNAL_DIR}/timespec_math.h
OBJS = 
LOBJS = test5.o func2.o  timespec_math.o
PROG = test5

#Call "make" with any of these labels in front to execute (default will be all)
all:	${PROG}

#removes the program and the objects and files that are created from compiling and executing the program
clean:
		rm ${PROG} ${FILES} ${LOBJS}

#clears the console then runs the program
play:
		clear
		.	/${PROG}


#=====Compilation======
${PROG}:	${OBJS} ${LOBJS}
			${CC} -Wall -lrt -D_REENTRANT -pthread  ${HEADER} ${OBJS} ${LOBJS} -o ${PROG}


test5.o: test5.c
	${CC} -Wall -c test5.c

func2.o: func2.c
		${CC} -Wall -c func2.c
timespec_math.o:  ${EXTERNAL_DIR}/timespec_math.c
	${CC} -Wall -c ${EXTERNAL_DIR}/timespec_math.c
