/*
 * memoria.c
 */

	/*MEM:
	/* Descreva (editando os coment�rios) o efeito em termos de mem�ria de cada
	    uma das declara��es e instru��es assinaladas com o coment�rio /*MEM:
	   Quais as zonas de mem�ria implicadas: armazenamento est�tico, pilha ou heap?
	   Alguma  mem�ria � reservada ou libertada? Se sim, onde esta essa mem�ria?
	   A instru��o em quest�o pode levar a uma fuga de mem�ria?
	  
	 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define DELTA 33

int calls, seed=356;   /* MEM: aloca��o de mem�ria est�tica - vari�veis globais (inicializadas por defeito a zero) */

int soma_ds(int a){    /* MEM: passagem do par�metro 'a' atrav�s da stack */
 int d=DELTA;          /* MEM: vari�vel local armazenadas na stack e inicializada com 33 */
 calls++; 			   /* MEM: actualiza��o da vari�vel global (mem�ria est�tica) */
 return a+d+seed; 
}   				   /* MEM: � adicionado um valor ao registo SP de forma descartar a stack frame */

int main() {
	int num;		   /* MEM: vari�veis locais armazenadas na stack frame de main() */
	int *ptr;
	int **handle;
	 
	 num = 14;								/* MEM: modifica o valor da vari�vel aramazenada na stack */
	 ptr = (int *)malloc(2 * sizeof(int));	/* MEM: aloca 4 bytes na heap (memoria din�mica) */
	 handle = &ptr;							/* MEM: inicializa um ponteiro para o ponteiro do bloco armazenado na heap */
	 **handle = num;						/* MEM: atribui o valor 14 � vari�vel do tipo int armazenada na mem�ria din�mica */
	 *(*handle+1) = num+1;					/* MEM: tenta escrever 15 na posi��o imediatamente a seguir ao bloco alocado na mem�ria din�mica (incorrecto!) */
	 *ptr = num-2;							/* MEM: atribui o valor 12 � vari�vel do tipo int armazenada na mem�ria din�mica */
	 ptr = &num;							/* MEM: atribui ao ponteiro o endere�o da vari�vel local 'num' */
	 *ptr = soma_ds(num-2);					/* MEM: passa o valor 12 � fun��o 'soma_ds()'  atrav�s da pilha;
												o resultado (12+356+33 = 401) � guardado na vari�vel local 'num' */

}
