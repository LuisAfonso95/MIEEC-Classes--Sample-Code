
#include <iostream>
using namespace std;


void desenhaZero(char elem, int dim);


int main (){
	int i;
	char a;
	
	cout << "Introduza 1 caracter e 1 numero inteiro impar de 5 a 41.\n";
	cin >> a >> i;	
		
	while( (i < 5 ) || (i > 41) || (i % 2 == 0) ){
		cout << "Erro. Introduza um numero impar entre 5 e 41\n";
		cin >> i;	
	}		

	desenhaZero(a, i);
	
	return(0);
}

void desenhaZero(char elem, int dim){

	int j;
	int k;

//1ª linha		
	cout << ' ';	
	j = 0;	
	while( j < (dim - 2) ){
		cout << elem;				
		j++;
	}
	cout << ' ' << endl;

//Linha intermédias
	k=0;
	while( k < (dim - 1) ){
		cout << elem;	
		j = 0;	
		while(j < (dim - 2) ){
			cout << ' ';				
			j++;
		}
		cout << elem << endl;
	k++;
	}

//Ultima linha
	cout << ' ';	
	j = 0;	
	while( j < (dim - 2) ){
		cout << elem;				
		j++;
	}
	cout << ' ' << endl;		
}
