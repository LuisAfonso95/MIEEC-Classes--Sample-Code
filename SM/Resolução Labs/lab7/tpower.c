#include <stdio.h>
#include <stdlib.h>
int main (int narg, char **argv) {
	int n, m, p;
	
	if (narg < 3){
		printf("Error: missing parameters\n\nUsage: tpower <base> <exponent>\n\n");
		exit(-1);
	}
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	if (m < 0){
		printf("Error: exponent must be non negative.\n\n");
		exit(-2);
	}		
	p = power(n, m);
	printf("%d^%d = %d\n\n", n, m, p);
	return p;
}
