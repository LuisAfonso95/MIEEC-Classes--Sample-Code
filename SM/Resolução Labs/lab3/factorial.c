#include <stdio.h>
#include <stdlib.h>

int factorial (int num)
{
	static int n;
	
	printf("call %d : !%d\n", ++n, num);
	if (num > 1) return (num*factorial(num-1));
	else return 1;
}

int main(int argc, char **argv)
{
	int num;
	
	if (argc < 2)
		printf("Error: missing parameter\n\nUsage: factorial <unsigned number>\n\nRui Rocha, Feb. 08\n\n\n");
	else
	{
		num = atoi(argv[1]);
		printf("\n%d! = %d\n\n\n", num, factorial(num));
	}	
	return 0;
}
