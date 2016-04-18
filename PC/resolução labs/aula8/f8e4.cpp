#include <iostream>
using namespace std;

bool eprimo (int);
int numeros_primos(int n, int tab[], int size);

int main(){
	int n;
	int size;
	
	do{
		cout << "Indique o numero a testar" << endl;
		cin >> n;
	}while(n <= 0);
	
	do{
		cout << "Indique agora a dimensão da tabela" << endl;
		cin >> size;
	}while( size <= 0);
		
	int tab[size];

	int c = numeros_primos(n, tab, size);
	
	cout << "Foram armazenados " << c << " numeros primos de 1 ate " << n << " num maximo de " << size << endl;
	cout << "Esses numeros sao: "<< endl;
	
	for(int i = 0; i < c; i++){
		cout << tab[i] << ", ";
	}
	

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

int numeros_primos(int n, int tab[], int size){
	int c = 0;
	
	for(int i = 0; i < n; i++){
		if( (eprimo(i)) && (c <= size-1) ){
			tab[c]=i;
			c++;	
		}
	}

	
	return(c);
}
