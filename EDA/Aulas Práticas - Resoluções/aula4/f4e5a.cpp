
#include <iostream>
#include <string>
using namespace std;


string nome;
int k=0;

int main(){
	
	cout << "\nIntroduza o seu nome proprio, tendo um maximo de 15 letras e um minimo de 3\n";  
	getline (cin,nome); 
	
		
	int i = 0;
	while(i  < int(nome.length()) ){
		if( ((nome[i]=='a') ||(nome[i]=='e') || (nome[i]=='i') || (nome[i]=='o') || (nome[i]=='u')) && 
		((nome[i]=='A') ||(nome[i]=='E') || (nome[i]=='I') || (nome[i]=='O') || (nome[i]=='U'))  ){	
			k++;					
		}
		i++;
	}
	cout << "O nome " << nome << " tem " << nome.length() << " letras" << endl;
	cout << " e " << k << " sao vogais" << endl;
}
