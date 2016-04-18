/* Incluir os headers do sistema necess�rios */
#include <stdlib.h>
#include <stdio.h>

/* Incluir o nosso header */
#include "vector.h"

/* Definir a nossa struct para os vectores */
struct _vector_t {
	size_t size;
	int *data;
};

/* Criar um novo vector com tamanho 1*/
vector_t *vector_new() {
	vector_t *retval;  

	/* Temos que primeiro alocar mem�ria para a nossa estrutura de dados */
	retval = (vector_t *)malloc(1 * sizeof(vector_t));

	/* Verificar o valor devolvido para ter a certeza que obtivemos a mem�ria pedida */
	if(retval == NULL)
		return NULL;
	 
	/* Temos agora que inicializar os dados */
	retval->size = 1;
	retval->data = (int *)malloc(retval->size * sizeof(int));

	/* Verificar o valor devolvido para ter a certeza que obtivemos a mem�ria pedida */
	if(retval->data == NULL) {
		free(retval);
		return NULL;
	}

	retval->data[0] = 0;

	/* Note que 'retval->size' poderia escrever-se '(*retval).size', 
	 * mas a nota��o '->' � mais pr�tica
	 */
	
	/* e terminamos com o ponteiro para o que se criou... */
	return retval;
}

//===============================================================================================
/* Libertar a mem�ria alocada para o vector passado � fun��o */
void vector_delete(vector_t *v){
	
	free(v -> data); 
	free(v);

}

//===============================================================================================
/* Devolver o valor de um elemento do vector */
int vector_get(vector_t *v, size_t loc) {

	/* Se foi passado um ponteiro NULL pointer para o vector
	 * protestar e devolver 0.
	 */

	if(v == NULL) {
		fprintf(stderr, "vector_get: passed a NULL vector.  Returning 0.\n");
		return 0;
	}

	/* Se a posi��o do elemento pretendido for maior que o tamanho alocado
	 * devolver 0, sen�o devolver o valor do elemento pretendido.
	 */
	if(loc < v->size) {
		return v->data[loc];
	} else {
		return 0;
	}
}

//==================================================================================================
/* Colocar um valor no vector */
void vector_set(vector_t *v, size_t loc, int value) {
	/* vector deve ter um comportamento din�mico, aceitando sempre mais elementos.
	 * O que fazer quando a localiza��o do elemento a colocar � maior que o tamanho j� alocado?
	 * N�o esquecer que elemntos n�o inicializados devem ficar a 0.
	 */


	if(loc >= v -> size){
		int *aux_data;
		aux_data = (int *) malloc ((loc + 1) * sizeof(int));
		int j;
		
	for (j = 0; j < v -> size; j++){
			aux_data[j] = v -> data[j];
		}
	for (j = v -> size; j < loc; j++){
			aux_data[j] = 0;
		}
		
		aux_data[loc] = value;
		v -> size = loc + 1;
		free (v -> data);
		v -> data = aux_data;
	} else {
		
		v -> data [loc] = value;
	}


}

//===============================================================================================
void vector_prune(vector_t *v, size_t loc){



vector_t *new;
int i;

	for(i=0;i<loc;i++) vector_set(new,i,dado);
		vector_delete(v);
		v=new;
}
//===============================================================================================

vector_t * vector_slipt(vector_t *v, size_t loc){

vector_t *novo;
int i;

	for(i=0;loc<v->size;loc++) novo[i]=v[loc+i];
	vector_prune(v,loc);
	return novo;
}

