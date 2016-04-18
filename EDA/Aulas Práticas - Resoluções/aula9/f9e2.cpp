#include <iostream>
#include <string>
using namespace std;

const int MAX_ELEM = 100;

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

void carrega(struct ID temp[], int a){
	
	for(int i = 0; i < a; i++){
		temp[i]=le();
	}
}

void mostra(struct ID temp[], int a){
	
	for(int i = 0; i < a; i++){
		cout << temp[i].nome << " com o BI " << temp[i].BI << " e altura " << temp[i].altura << endl;
	}
}



int main(){
	
	int a;
	struct ID temp[100];
	cin >> a;
	if (a >= 100){
		return(0);
	}	
	cin.ignore();
	carrega(temp, a);
	mostra(temp, a);
	return (0);
	
	
}
