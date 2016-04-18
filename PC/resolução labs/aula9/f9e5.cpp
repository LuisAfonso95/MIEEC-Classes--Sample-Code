#include <iostream>
#include <string>
using namespace std;

void desenhaX(int a){

char FCTUC[5]={'F','C','T','U','C'};
int v=0;
	
	for(int i = 0; i < (a-1)/2; i++){
		if (v > 4) v=0;
		for(int k = 0; k < a; k++){
			
			if( (k==i) || k==((a-1)-i) ){
				cout << FCTUC[v];
			}
			else{
				cout << " ";
			}
			
		}
		v++;
		cout << endl;
	}
	
	if (v > 4) v=0;
	for(int i = 0; i < a; i++){
		if ( i == (a/2)){
			cout << FCTUC[v];
		}
		else{
			cout << " ";
		}
	}
	v++;
	cout << endl;
	
	for(int i = ((a-1)/2)-1; i >= 0; i--){
		if (v > 4) v=0;
		for(int k = 0; k < a; k++){
			
			if( (k==i) || k==((a-1)-i) ){
				cout << FCTUC[v];
			}
			else{
				cout << " ";
			}
		}
		v++;
		cout << endl;
	}
		
}

void desenhaXchar(const string & frase, int a){

int v=0;
	
	for(int i = 0; i < (a-1)/2; i++){
		if (v > a-1) v=0;
		for(int k = 0; k < a; k++){
			
			if( (k==i) || k==((a-1)-i) ){
				cout << frase[v];
			}
			else{
				cout << " ";
			}
			
		}
		v++;
		cout << endl;
	}
	
	if (v > a-1) v=0;
	for(int i = 0; i < a; i++){
		if ( i == (a/2)){
			cout << frase[v];
		}
		else{
			cout << " ";
		}
	}
	v++;
	cout << endl;
	
	for(int i = ((a-1)/2)-1; i >= 0; i--){
		if (v > a-1) v=0;
		for(int k = 0; k < a; k++){
			
			if( (k==i) || k==((a-1)-i) ){
				cout << frase[v];
			}
			else{
				cout << " ";
			}
		}
		v++;
		cout << endl;
	}
		
}

int main(){
	
	string frase;
	/*int a;
	cout << "Introduza um numero impar de 1 a 15" << endl;
	cin >> a;
	while( (a%2 == 0) || (a > 15) || (a < 1) ){
		cout << "Introduza um numero impar de 1 a 15" << endl;
		cin >> a;		
	}
	desenhaX(a);*/
	
	getline(cin, frase, '.');

	
	if(frase.size()%2 == 0){
		int size = frase.size();
		 frase.insert(size,1,'!');
		
	}

	desenhaXchar(frase, frase.size());
}
	
