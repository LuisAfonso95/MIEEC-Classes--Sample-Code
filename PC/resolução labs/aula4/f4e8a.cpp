
#include <iostream>
#include <string>
using namespace std;

const int MAX_CAP=12;


string palavra;
bool OK= 0;

int main(){
	
	cout << "\nIntroduza uma palavra composta apenas por minusculas até 12 letras\n";
	getline (cin,palavra); 
	
	
	while(OK==false){
		if(int(palavra.length())>MAX_CAP){
			cout << "ERRO. Foram introduzidos mais de 12 letras\n";
			cout << "Por favor repita mas desta vez com um maximo de 12 letras\n";
			getline (cin,palavra); // no c++ devia ser cin >> ...-
		}
		else{
			OK=true;
		}		
		for(int i=0; i < int(palavra.length());i++){
			if ( (palavra[i] < 'a') || (palavra[i] > 'z') ) {
				OK=false;
				cout << "ERRO. Foram introduzidos letras nao minusculas\n";
				cout << "Por favor repita mas desta vez com apenas letras minusculas\n";
				getline (cin,palavra); 
			}
		}			
	}
	
	for(int i=int(palavra.length()) ; i >= 0 ; i--){
		cout << palavra[i];
	}
	cout << endl;
		
	
	
}
