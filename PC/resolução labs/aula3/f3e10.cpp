  
 #include <string>
#include <iostream>
using namespace std;
  
char letras[2];
char temp[2];
  
int main (){
	cout << "Introduza 2 letras\n";
	cin >> letras[0] >> letras[1];
	
	//Guarda-se os caracteres introduzidos numa variavel.
	temp[0]=letras[0];
	temp[1]=letras[1];
	//Converte-se as maiusculas para minusculas, caso seja não sejam minusculas
	if ( letras[0] < 'a'){
		letras[0]=letras[0]+('a'-'A');
	}
	if ( letras[1] < 'a'){
		letras[1]=letras[1]+('a'-'A');
	}
	
	while( (letras[0] < 'a') || (letras[0] > 'z')){
		cout << "\nO primeiro caracter nao e uma letra.";
		cout << "\nPor favor introduza apenas letras\n"; 
	    cin >> letras[0];
	    	//Guarda-se os caracteres introduzidos numa variavel.
			temp[0]=letras[0];
			//Converte-se as maiusculas para minusculas, caso seja não sejam minusculas
			if ( letras[0] < 'a'){
				letras[0]=letras[0]+('a'-'A');
			}
	 }
	 
	while( (letras[1] < 'a') || (letras[1] > 'z')){
		cout << "\nO segundo caracter nao e uma letra.";
		cout << "\nPor favor introduza apenas letras\n"; 
	    cin >> letras[1]; 
	    	//Guarda-se os caracteres introduzidos numa variavel.
			temp[1]=letras[1];
			//Converte-se as maiusculas para minusculas, caso seja não sejam minusculas
			if ( letras[1] < 'a'){
				letras[1]=letras[1]+('a'-'A');
			}
	 }	
	 
	//Estes seguintes verificam qual das letras é maior na tabela de ASCII, que é igual à ordem alfabética
	if( letras[0] < letras[1] ){
		cout << "\nA suas letras por ordem alfabetica: " << temp[0] << ", " << temp[1] << endl;  
	 }
	 else{
		cout << "\nA suas letras por ordem alfabetica: " << temp[1] << ", " << temp[0] << endl;   
	 }
	 
}
