

#include <iostream>
using namespace std;

int i;
char a;




int main (){
	cout << "Introduza 1 caracter e 1 numero inteiro impar de 5 a 41.\n";
	cin >> a >> i;	
		
	while( (i < 5 ) || (i > 41) || (i % 2 == 0) ){
		cout << "Erro. Introduza um numero impar entre 5 e 41\n";
		cin >> i;	
	}	
		
//1ª linha		
	cout << ' ';	
	for(int j = 0; j < (i - 2); j++ ){
		cout << a;				
	}
	cout << ' ' << endl;

//Linha intermédias	
	for(int k = 0; k < (i - 2); k++ ){
		cout << a;	
		for(int j = 0; j < (i - 2); j++ ){
			cout << ' ';				
		}
		cout << a << endl;
	}


//Ultima linha
	cout << ' ';		
	for(int j = 0 ; j < (i - 2); j++ ){
		cout << a;				
	}
	cout << ' ' << endl;	
	
}
