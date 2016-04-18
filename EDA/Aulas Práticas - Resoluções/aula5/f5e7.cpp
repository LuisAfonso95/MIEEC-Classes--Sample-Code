#include <iostream>
#include <string>

using namespace std;

string nome[4];
string nome1;
string nome2;
string nome3;
string nome4;
int idade[4];
float altura[4];

int main (){


	for(int i = 0; i <=3; i++){
		 
		cout << "Introduza o seu nome completo\n";
		getline(cin,nome[i]);


		while( nome[i].length() > 45){
			cout << "\nPor favor repita o seu nome com um maximo de 45 caracteres\n";
			getline(cin,nome[i]);
		}
	
		cout << "\nQual é a sua idade?\n";
		cin >> idade[i];

	
		cout << "\nE a sua altura em metros?\n";
		cin >> altura[i];
		cin.ignore(2,'\n');
	}
	
	for(int i = 0; i <=3; i++){
		cout << nome[i] << ", " << idade[i] << " anos, " << altura[i] << "m" << endl;
	}
		
		
	
}
