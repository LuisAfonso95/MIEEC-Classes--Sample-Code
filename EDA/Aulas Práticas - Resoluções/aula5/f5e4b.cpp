#include <iostream>
using namespace std;

int i;
int d;


int main (){
	cout << "Introduza 1 numero inteiro de 1 a 9.\n";
	cin >> i;
	d = i;	
		
	while( (i < 1 ) || (i > 9) ){
		cout << "Erro. Introduza 1 numero inteiro de 1 a 9.\n";
		cin >> d;	
	}	
		
//1ª linha		
	for(int j = 0; j < i ; j++ ){
		cout << d;				
	}
	cout << endl;
	d-=1;

//Linha intermédias	
	for(int k = 0; k < (i - 2); k++ ){
		cout << d;	
		for(int j = 0; j < (i - 2); j++ ){
			cout << ' ';				
		}
		cout << d << endl;
		d-=1;
	}


//Ultima linha	
	if(i!=1){	
		for(int j = 0 ; j < i; j++ ){
			cout << d;				
		}	
		cout << endl;
	}
	
}

