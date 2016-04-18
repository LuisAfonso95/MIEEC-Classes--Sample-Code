//===================================================
// 1º parte TPC da 1ª aula
//
// Autor: Luís Rafael Afonso Data:2013/09/21
//
// Objectivo: Demonstrar a diferença entre contas entre inteiros e números de vírgula flutuante.
//
// Utilizacao: Executar o código e observar o que aparece na linha de comandos
//===================================================

#include <iostream>
using namespace std;	//Assim pode-se omitir "std" antes de qualquer objecto (cout/cin)


int i, j;	//Declaração de variaveis inteiras 
float x, y;	//Declaração de variaveis de vírgula flutuante


int main()
{ 
	//Guarda-se nas variaveis números, tendo de haver equivalentes entre ints e floats (i=x, j=y).
	i = 10;
	j = 6;
	x = 10.0;
	y = 6.0;

	//Escreve na linha de comandos os resultados das divisões com os tipos de váriaveis diferentes
	cout << "\nNuma divisão com inteiros, 10/6 dá: " << i/j;
	cout << "\nMas se usarmos floats já dá: " << x/y << endl;	
}
