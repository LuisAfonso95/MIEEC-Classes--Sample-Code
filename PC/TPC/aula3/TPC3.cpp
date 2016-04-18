//===================================================
// 	TPC 3ª aula.
//
// 	Autor: Luís Rafael Afonso 	Turma:PL6
// 	Data:2013/10/03
//
// 	Objectivo: Pedir uma frase e 1 caracter. Depois verificar quantos caracteres
//dessa mesma frase eram maiores que o caracter pedido,
//
// 	Utilizacao: Introduzir uma frase qualquer e depois 1 caracter qualquer.
//	Será mostrado quantos caracteres são superiores em valor (na tabela ASCII),
//o caracter introduzido entre ' ' e ainda o seu valor em ASCII.
//===================================================

#include <cstring>
#include <string>
#include <iostream>
using namespace std;
    
//	Usa-se uma string C para poder se usar o getline que permite não 
//escrever para alem da memoria da variavel e poder usar caracteres
//como o espaço
char letra[2];		

string frase;						
int i = 0;			
int k = 0;
  
int main (){

	//	Pede e regista na string C++ uma frase.
	cout << "\nIntroduza uma frase\n";
	getline (cin,frase);
	
	//	Pede um caracter e regista para ver se há algum de valor superior a ele na frase anterior
	cout << "\nAgora introduza o character que quer contar\n";
	cin.getline(letra,sizeof(letra));

	while(i <= int(frase.length())){     //	Loop enquanto i for menor que o tamanho da string
		if(frase[i] > letra[0]){		 //	Se um dos caracteres da string for superior ao caracter introduzido
			k++;                         //então incrementa k
		}
		i++;							//	Incrementação de i para ler os varios caracteres da string
	}

	
	cout << "\nA sua frase tinha "<< k <<" characteres com codigo ASCII superiores a: '" << letra[0] 
	<< "' com o valor " << int(letra[0]) << endl;
}

//	Semelhanças com o problema 6:
//	Uso de uma string C++ para registar a frase introduzida.
//	Verificação de cada 1 dos caracteres da frase
//	Usei tambem um string C, talvez desnecessáriamente, para poder registar os espaço,
//e conseguir a função "getline", que me permite não escrever em registos que não deve
