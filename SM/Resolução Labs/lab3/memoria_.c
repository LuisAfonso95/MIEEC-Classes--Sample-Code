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

int calls, seed=356;   /* MEM: alocação de memória estática - variáveis globais (inicializadas por defeito a zero) */

int soma_ds(int a){    /* MEM: passagem do parâmetro 'a' através da stack */
 int d=DELTA;          /* MEM: variável local armazenadas na stack e inicializada com 33 */
 calls++; 			   /* MEM: actualização da variável global (memória estática) */
 return a+d+seed; 
}   				   /* MEM: é adicionado um valor ao registo SP de forma descartar a stack frame */

int main() {
	int num;		   /* MEM: variáveis locais armazenadas na stack frame de main() */
	int *ptr;
	int **handle;
	 
	 num = 14;								/* MEM: modifica o valor da variável aramazenada na stack */
	 ptr = (int *)malloc(2 * sizeof(int));	/* MEM: aloca 4 bytes na heap (memoria dinâmica) */
	 handle = &ptr;							/* MEM: inicializa um ponteiro para o ponteiro do bloco armazenado na heap */
	 **handle = num;						/* MEM: atribui o valor 14 à variável do tipo int armazenada na memória dinâmica */
	 *(*handle+1) = num+1;					/* MEM: tenta escrever 15 na posição imediatamente a seguir ao bloco alocado na memória dinâmica (incorrecto!) */
	 *ptr = num-2;							/* MEM: atribui o valor 12 à variável do tipo int armazenada na memória dinâmica */
	 ptr = &num;							/* MEM: atribui ao ponteiro o endereço da variável local 'num' */
	 *ptr = soma_ds(num-2);					/* MEM: passa o valor 12 à função 'soma_ds()'  através da pilha;
												o resultado (12+356+33 = 401) é guardado na variável local 'num' */

}
