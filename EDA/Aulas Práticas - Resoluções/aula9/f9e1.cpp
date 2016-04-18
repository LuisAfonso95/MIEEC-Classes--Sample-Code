#include <iostream>
#include <string>
using namespace std;


struct ID{
	string nome;
	unsigned int BI;
	float altura;
};



struct ID le(){
	struct ID temp;
	
	cout << "Introduza o seu nome" << endl;
	getline(cin,temp.nome);
	cout << "Introduza o seu numero de BI" << endl;
	cin >> temp.BI;
	cout << "E por fim, introduza a sua altura em metros" << endl;
	cin >> temp.altura;
	cin.ignore();
	return temp;
}

void mostra(struct ID temp){
	cout << temp.nome << " com o BI " << temp.BI << " e altura " << temp.altura;
}

int main(){
	struct ID temp;
	temp = le();
	mostra(temp);
	return(0);
}



