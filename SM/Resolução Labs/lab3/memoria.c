/*
 * memoria.c
 */

	/*MEM:
	/* Descreva (editando os comentários) o efeito em termos de memória de cada
	    uma das declarações e instruções assinaladas com o comentário /*MEM:
	   Quais as zonas de memória implicadas: armazenamento estático, pilha ou heap?
	   Alguma  memória é reservada ou libertada? Se sim, onde esta essa memória?
	   A instrução em questão pode levar a uma fuga de memória?
	  
	 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define DELTA 33

int calls, seed=356;   /*MEM:*/

int soma_ds(int a){     /*MEM:*/
 int d=DELTA;           /*MEM:*/
 calls++; 				/*MEM:*/
 return a+d+seed; 
}   					/*MEM:*/

int main() {
	int num;								/*MEM:*/
	int *ptr;
	int **handle;
	 
	 num = 14;								/*MEM:*/
	 ptr = (int *)malloc(2 * sizeof(int));	/*MEM:*/
	 handle = &ptr;							/*MEM:*/
	 **handle = num;						/*MEM:*/
	 *(*handle+1) = num+1;					/*MEM*/
	 *ptr = num-2;							/*MEM:*/
	 ptr = &num;							/*MEM:*/
	 *ptr = soma_ds(num-2);					/*MEM:*/

}
