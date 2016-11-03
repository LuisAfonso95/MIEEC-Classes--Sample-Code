
#====Variables====
EXTERNAL_DIR=../common_files
CC = gcc
HEADER = ${EXTERNAL_DIR}/func.h ${EXTERNAL_DIR}/timespec_math.h
OBJS = 
LOBJS = test6_1.o func2.o  timespec_math.o
PROG = test6_1

#Call "make" with any of these labels in front to execute (default will be all)
all:	${PROG}

#removes the program and the objects and files that are created from compiling and executing the program
clean:
		rm ${PROG} ${FILES} ${LOBJS}

#clears the console then runs the program
play:
		clear
		sudo ./${PROG}


#=====Compilation======
${PROG}:	${OBJS} ${LOBJS}
			${CC} -Wall -lrt -D_REENTRANT -pthread  ${HEADER} ${OBJS} ${LOBJS}  -o ${PROG}


test6_1.o: test6_1.c
	${CC} -Wall -c test6_1.c

func2.o: ${EXTERNAL_DIR}/func2.c
		${CC} -Wall -c ${EXTERNAL_DIR}/func2.c
timespec_math.o:  ${EXTERNAL_DIR}/timespec_math.c
	${CC} -Wall -c ${EXTERNAL_DIR}/timespec_math.c
