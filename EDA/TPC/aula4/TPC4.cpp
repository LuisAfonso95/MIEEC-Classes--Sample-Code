//===================================================
// 	TPC 4ª aula.
//
// 	Autor: Luís Rafael Afonso 	Turma:PL6
// 	Data:2013/10/03
//
// 	Objectivo: Contar quantos numeros introduzidos são divisiveis por um outro
//número introduzido
//
// 	Utilizacao: Introduzir 6 números inteiros e depois introduzir o divisor.
//Observa-se o resultado na linha de comandos
//===================================================

#include <cstring>
#include <string>
#include <iostream>
using namespace std;
    

int numero[6];
int divisor;
int k=0;
int reg[6];

int main (){

	//Pedido e registo de 6 números
	cout << "\nIntroduza 6 numeros inteiros\n";
	for(int i=0;i<6;i++){
		cin >> numero[i];
	}
	
	//Aqui pede e regista o divisor
	cout << "\nAgora introduza apenas 1 numero inteiro\n";
	cin >> divisor;

	//Aqui divide cada numero pelo divisor. Caso o resto seja 0 então incrementa k e regista qual foi esse numero.	
	for(int i=0;i<6;i++){
		if (numero[i]%divisor==0){
			reg[k]=numero[i];
			k++;
		}
	}
	
	
	//Apresenta o número de números divisiveis pelo divisor e quais foram esses números
	cout << "\n Há " << k << " numeros diviseis por " << divisor << endl;
	cout << "e esses numeros eram ";
	for(int i=0; i<k; i++){
		cout << reg[i] << " ";
	}
	cout << endl;
		
}

