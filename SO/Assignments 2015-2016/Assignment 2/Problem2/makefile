
#====Variables====
CC = gcc
HEADER = Problem2.h
OBJSR = Problem2_receiver.o 
OBJSS = Problem2_sender.o
PROGR = receiver
PROGS = sender
FILES = 

#Call "make" with any of these labels in front to execute (default will be all)
all:	${PROGS} ${PROGR}

#removes the program, the objects and the files that are created from running the program
clean:
		rm ${OBJSR} ${OBJSS} ${PROGR} ${PROGS} ${FILES}


#=====Compilation======
${PROGS}:	${OBJSS}
			${CC}   ${HEADER} ${OBJSS}  -Wall  -o  ${PROGS} -lrt
${OBJSS} : Problem2_sender.c
	${CC}  -Wall -c Problem2_sender.c


${PROGR}:	${OBJSR}
			${CC}   ${HEADER} ${OBJSR}  -Wall  -o  ${PROGR} -lrt
${OBJSR} : Problem2_receiver.c
	${CC} -Wall -c Problem2_receiver.c

