
#include <iostream>
using namespace std;

int i;
char a;

int j;
int k;




int main (){
	cout << "Introduza 1 caracter e 1 numero inteiro impar de 5 a 41.\n";
	cin >> a >> i;	
		
	while( (i < 5 ) || (i > 41) || (i % 2 == 0) ){
		cout << "Erro. Introduza um numero impar entre 5 e 41\n";
		cin >> i;	
	}	

//1ª linha		
	cout << ' ';	
	j = 0;	
	while( j < (i - 2) ){
		cout << a;				
		j++;
	}
	cout << ' ' << endl;

//Linha intermédias
	k=0;
	while( k < (i - 1) ){
		cout << a;	
		j = 0;	
		while(j < (i - 2) ){
			cout << ' ';				
			j++;
		}
		cout << a << endl;
	k++;
	}

//Ultima linha
	cout << ' ';	
	j = 0;	
	while( j < (i - 2) ){
		cout << a;				
		j++;
	}
	cout << ' ' << endl;	
	
}
