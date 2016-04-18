//===================================================
// 	TPC 2ª aula. Parte a)
//
// 	Autor: Luís Rafael Afonso 	Turma:PL6
// 	Data:2013/09/26
//
// 	Objectivo: Tranformar as minúsculas de um nome para maiúscula,
//	usando strings de C
//
// 	Utilizacao: Introduzir um nome de 5 letras, respeitando a 
//	maiúscula na primeira letra
//===================================================

#include <iostream>
using namespace std;

char nome[6];

int main(){
	
	cout << "Introduza um único nome de 5 letras\n";
	cin.getline (nome,sizeof(nome)); 
	for (int i=1; i<6; i++){
		nome[i]=nome[i]+('A'-'a');
	}
	nome[5]='\0';
	cout << "O nome dado em maiúsculas: " << nome << endl;
}
