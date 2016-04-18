#include <stdio.h>
#include <stdlib.h>

int main (int narg, char **argv) {
	int x[5], i, r;
	
	if (narg < 6){
		printf("Error: missing parameters\n\nUsage: somapond x1 x2 x3 x4 x5\n\n");
		exit(-1);
	}
	for (i=0;i<5;i++) x[i]=atoi(argv[i+1]);
	r = somapond(x[0], x[1], x[2], x[3], x[4]);
	printf("f(%d,%d,%d,%d,%d) = 16*%d+8*%d+4*%d+2*%d+%d = %d\n\n",
		x[0], x[1], x[2], x[3], x[4],
		x[0], x[1], x[2], x[3], x[4], r);
	return r;
}
