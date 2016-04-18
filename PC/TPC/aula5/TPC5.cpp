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

#include <iostream>
using namespace std;

char a, b;
int i;
bool r;

int main(){
	cout << "Introduza 2 caracteres diferentes\n";
	cin >> a >> b;
	
	while(a == b){
		cout <<	"Por favor introduza um caractere diferente de " << a << endl;
		cin >> b;
	}
	
	cout << "\nAgora introduza 1 inteiro\n";
	cin >> i;
	while( ((i % 2) != 0) || (i < 4) || (i >40) ){
		cout <<	"O numero tem de ser par de 4 a 40\n";
		cin >> i;
	}		
	
	for(int k = 0; k <=i; k++){
		r^=1;
		for(int j = 0; j <=k; j++){
			if((j % 2) == r) {
				cout << a;
			}
			else{
				cout << b;
			}
		}
		cout << endl;
	}
	
	
	
}
