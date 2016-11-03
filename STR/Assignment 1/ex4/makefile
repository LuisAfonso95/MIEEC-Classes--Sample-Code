
#====Variables====
EXTERNAL_DIR=../common_files
CC = gcc
HEADER = ${EXTERNAL_DIR}/func.h ${EXTERNAL_DIR}/timespec_math.h
OBJS =  ${EXTERNAL_DIR}/func.o  
LOBJS = test4.o timespec_math.o
PROG = test4
FILES = ex4_MatLab_Values.txt

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
			${CC} -Wall -lrt -D_REENTRANT -pthread  ${HEADER} ${OBJS}  ${LOBJS} -o ${PROG}


test4.o: test4.c
	${CC} -Wall -c test4.c

timespec_math.o:  ${EXTERNAL_DIR}/timespec_math.c
	${CC} -Wall -c ${EXTERNAL_DIR}/timespec_math.c
