
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_CAP=16;

char nome[MAX_CAP];
int k=0;


int main(){
	
	cout << "\nIntroduza o seu nome proprio, tendo um maximo de 15 letras e um minimo de 3\n";  
	cin.getline (nome,sizeof(nome)); 
	
	int i = 0;
	while(i  < int(strlen(nome)) ){
		if( ((nome[i]=='a') ||(nome[i]=='e') || (nome[i]=='i') || (nome[i]=='o') || (nome[i]=='u')) && 
		((nome[i]=='A') ||(nome[i]=='E') || (nome[i]=='I') || (nome[i]=='O') || (nome[i]=='U'))  ){	
			k++;					
		}
		i++;
	}
	cout << "O nome " << nome << " tem " << strlen(nome) << " letras" << endl;
	cout << " e " << k << " sao vogais" << endl;
}
