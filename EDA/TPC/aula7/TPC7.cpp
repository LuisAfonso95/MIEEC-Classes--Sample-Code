//===================================================
// 	TPC 7ª aula.
//
// 	Autor: Luís Rafael Afonso 	Turma:PL6
// 	Data:2013/11/10
//
// 	Objectivo: Receber 3 numeros e mostrá-los por ordem crescente
//
// 	Utilizacao: Introduza 3 numeros inteiros
//===================================================

#include <iostream>
using namespace std;

void modulo(int*);
	
int main(){
	int tab[5];
	
	for(int i=0; i<5; i++)
	
	cin >> tab[i];
	
	modulo(tab);

	cout <<endl<<"modulo da tabela:";
	
	for(int i=0; i<5; i++)
		cout <<endl<< tab[i]<<endl;
		
return 0;
	
}

void modulo( int *n){
	
	for(int i=0; i<5; i++)
		if (n[i] < 0) 
			n[i]= -n[i];
	

}
