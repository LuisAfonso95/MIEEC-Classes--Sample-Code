//===================================================
// 	TPC 2ª aula. Parte b)
//
// 	Autor: Luís Rafael Afonso 	Turma:PL6
// 	Data:2013/09/26
//
// 	Objectivo: Tranformar as minúsculas de um nome para maiúscula,
//	usando strings de C++
//
// 	Utilizacao: Introduzir um nome de 5 letras, respeitando a 
//	maiúscula na primeira letra
//===================================================

#include <iostream>
#include <string>
using namespace std;

string nome(5,'A');

int main(){
	cout << "Introduza um único nome de 5 letras\n";
	getline (cin,nome); 
	for (int i=1; i<6; i++){
		nome[i]=nome[i]+('A'-'a');
	}
	cout << "O nome dado em maiúsculas: " << nome << endl;
}
