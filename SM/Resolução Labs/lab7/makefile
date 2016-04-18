power: power.o tpower.o
	gcc power.o tpower.o -o power
power.o: power.s
	gcc -c -x assembler power.s
tpower.o: tpower.c
	gcc -c tpower.c
