
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_CAP=12;


char palavra[200];
bool OK= 0;

int main(){
	
	cout << "\nIntroduza uma palavra composta apenas por minusculas até 12 letras\n";
	cin.getline (palavra,sizeof(palavra));
	
	
	while(OK==false){
		if(int(strlen(palavra))>MAX_CAP){
			cout << "ERRO. Foram introduzidos mais de 12 letras\n";
			cout << "Por favor repita mas desta vez com um maximo de 12 letras\n";
			cin.getline (palavra,sizeof(palavra));
		}
		else{
			OK=true;
		}		
		for(int i=0; i < int(strlen(palavra));i++){
			if ( (palavra[i] < 'a') || (palavra[i] > 'z') ) {
				OK=false;
				cout << "ERRO. Foram introduzidos letras nao minusculas\n";
				cout << "Por favor repita mas desta vez com apenas letras minusculas\n";
				cin.getline (palavra,sizeof(palavra)); 
			}
		}			
	}
	
	for(int i=int(strlen(palavra)) ; i >= 0 ; i--){
		cout << palavra[i];
	}
	cout << endl;
		
	
	
}

