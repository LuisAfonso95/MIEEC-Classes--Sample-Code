#include <iostream>

using namespace std;

bool edigito (char a); 
bool eletra (char a);
bool emaiuscula (char a);
bool eminuscula (char a);
int letra2int (char a);


int main(){
	char a;
	
	cout << "Introduza um caracter: ";
	
	cin >> a;
	
	if( edigito(a) ){
		cout << letra2int(a) << endl;
	}
	else if ( !eletra(a) ){
		cout << "Nao foi introduzido nem um numero nem uma letra" << endl;
	}		
	else if( emaiuscula(a) ){
		cout << "Foi introduzida uma letra maiuscula" << endl;	
	}
	else if( eminuscula(a) ){
		cout << "Foi introduzida uma letra minuscula" << endl;		
	}
	
	
	
	return(0);
	
	
}

bool edigito (char a){
	/*bool digito;
	
	if( (a >='0') && (a <= '9') ){
		digito = true;
	}
	else{
		digito = false;
	}
	
	return(digito);	*/
	return((a >='0') && (a <= '9'));
}

bool eletra (char a){
	bool letra;
	
	if( ((a >= 'a') && (a <= 'z')) || ((a >= 'A') && (a <= 'Z')) ){
		letra = true;
	}
	else{
		letra = false;
	}
	
	return(letra);
}

bool emaiuscula (char a){
	bool maiuscula;
	
	if( (a >= 'A') && (a <= 'Z') ){
		maiuscula = true;
	}
	else{
		maiuscula = false;
	}
	
	return(maiuscula);	
	
}

bool eminuscula (char a){
	bool minuscula;
	
	if( (a >= 'a') && (a <= 'z') ){
		minuscula = true;
	}
	else{
		minuscula = false;
	}
	
	return(minuscula);	
	
}
	
int letra2int (char a){
	
	if( edigito(a) ){
		
		return(a-'0');
	}
	else{
		return(-1);
	}

}

	

