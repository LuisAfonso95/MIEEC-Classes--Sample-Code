#include <iostream>
using namespace std;

bool eprimo (int);
int numeros_primos(int tab[], int size);

int main(){
	const int size=14;
	int tab[size]= {2, 3, 5, 7, 12 , 18, 33, 200, 22, 29, 31, 37, 41, 43}; //9 primos
	
	int n = numeros_primos(tab, size);
	
	cout << "Ha " << n << " numeros primos na tabela"<< endl;
	

}

int numeros_primos(int tab[], int size){
	int c=0;
	
	for(int i=0; i < size; i++){
		if(eprimo(tab[i])){
			c++;
		}
	}
	
	return(c);
	
}

bool eprimo (int n){
	bool nprimo = 1;
	int c = 0 ;
	
	if( n > 1 ){
		for(int i = n; i > 0; i--){
			if( n % i ==0){
				c++;
			}
		}
		if (c > 2){
			nprimo=0;
		}
	}
	else{
		nprimo=0;
	}
	
	return(nprimo);	
}


