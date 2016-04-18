//===================================================
// 2º parte TPC da 1ª aula
//
// Autor: Luís Rafael Afonso Data:2013/09/21
//
// Objectivo: Pedir 2 números e apresentar o resultado das 4 contas elementares.
//
// Utilizacao: Executar o código e introduzir os números por ordem.
//===================================================


#include <iostream>
using namespace std;	//Assim pode-se omitir "std" antes de qualquer objecto (cout/cin)


int i, j;	//Declaração de variaveis inteiras


int main()	//Bloco principal
{       
	cout << "\nIntroduza o primeiro número inteiro ";	//Escreve na linha de comandos o 1º pedido
	cin >> i;											//Espera pela introdução do 1º número e guarda-o na variavel i
	cout << "Agora introduza o segundo " << endl;		//Escreve na linha de comandos o 2º pedido
	cin >> j;											////Espera pela introdução do 2º número e guarda-o na variavel j	
	
	//Aqui escreve na linha de comandos os resultados de cada conta
	cout << "\nAdicionando: " << i << '+' << j << '=' << i+j ;	
	cout << "\nSubtraindo: " << i << '-' << j << '=' << i-j ;
	cout << "\nMultiplicando: " << i << '*' << j << '=' << i*j ;
	cout << "\nDividindo: " << i << '/' << j << '=' << i/j << " Com o resto = " << i%j << endl;
}
