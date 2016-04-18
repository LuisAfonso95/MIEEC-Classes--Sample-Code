#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include "vector.h"

int leFichMusica(char * nome_ficheiro, vector_t ** notas, vector_t ** tempos) {
// le a sequencia de notas e duracao (melodia+ritmo) de um ficheiro de texto com o
// formato:
//
// nota1  tempo1
// nota2  tempo2
//  ...
// Retorna em *notas e *tempos ponteiros para vectores com notas e tempos.
//
	int freq, tempo, num=0;
	FILE *fid;
	char str[32];
	char *r;

	printf("Le musica no ficheiro '%s'\n", nome_ficheiro);
	fid=fopen(nome_ficheiro, "r");
	*notas = vector_new();
	*tempos = vector_new();
	if (fid!=NULL && *notas!=NULL && *tempos!=NULL)
	{
		do{
			r=fgets(str,32,fid);
			if (r!=NULL)
			{
				sscanf(str,"%d %d", &freq, &tempo);	//leitura do par (frequencia,tempo)
				printf(" Leitura: nota = %d\ttempo = %d.\n", freq, tempo);
				vector_set(*notas, num, freq);
				vector_set(*tempos, num++, tempo);
			}
		}while (r!=NULL);
		printf("Numero de notas musicais lidas = %d.\n\n",num);
		fclose(fid);
		return num;
	}
	else
	{
		printf("Erro ao abrir o arquivo de dados ou ao alocar memória!\n\n");
		exit(-1);
	}
} // leFichMusica
//-------------------------------------------------------------------

