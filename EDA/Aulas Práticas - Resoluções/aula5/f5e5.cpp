#include <iostream>
using namespace std;

int i;


int main (){
		
	cout << "Introduza um numero de 1 a 9.\n";
	cin >> i;
	
	while( (i < 1) || (i > 9) ){
		cout << "Erro. Introduza um numero de 1 a 9.\n";
		cin >> i;		
	}
	cout << endl;
	
//1ª linha		
	for(int j = 0; j < (2*i) ; j++ ){
		cout << i;				
	}
	cout << endl;

//Linha intermédias	
	for(int k = 0; k < (i - 2); k++ ){
		cout << i;	
		for(int j = 0; j < ((2 * i) - 2); j++ ){
			cout << ' ';				
		}
		cout << i << endl;
	}


//Ultima linha	
	if(i!=1){
		for(int j = 0 ; j < (2*i); j++ ){
			cout << i;				
		}	
		cout << endl;
	}
			
			
			
	
}

