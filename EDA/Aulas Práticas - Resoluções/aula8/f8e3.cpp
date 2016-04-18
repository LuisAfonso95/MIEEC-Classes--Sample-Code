

#include <iostream>
using namespace std;

bool primo (int);

int main(){
	int n;
	
	cin >> n;
	if(primo(n)){
		cout << "O numero introduzido e primo" << endl;
	}
}


bool primo (int n){
	bool nprimo = 1;
	int c = 0 ;
	int l = 0;
	int numero [n];
	
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
	
	for(int k = n; k > 1; k--){
		c=0;
		for(int i = k; i > 0; i--){
			
			if( k % i == 0){
				c++;
			}
		}
		
		if (c == 2){		
			numero[l]=k;	
			l++;
		}
	}
	
	l--;
	while(l >= 0){
		cout << "O numero " << numero[l] << " e primo "<< endl;
		l--;
	}
	cout<< endl;
	
	return(nprimo);
	
	
}
