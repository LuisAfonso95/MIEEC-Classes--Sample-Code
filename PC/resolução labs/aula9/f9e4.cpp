#include <iostream>
#include <string>
using namespace std;

void desenhaX(int a){
	
	for(int i = 0; i < (a-1)/2; i++){
		for(int k = 0; k < a; k++){
			
			if( (k==i) || k==((a-1)-i) ){
				cout << "X";
			}
			else{
				cout << " ";
			}
		}
		cout << endl;
	}
	
	for(int i = 0; i < a; i++){
		if ( i == (a/2)){
			cout << "X";
		}
		else{
			cout << " ";
		}
	}
	cout << endl;
	
	for(int i = ((a-1)/2)-1; i >= 0; i--){
		for(int k = 0; k < a; k++){
			
			if( (k==i) || k==((a-1)-i) ){
				cout << "X";
			}
			else{
				cout << " ";
			}
		}
		cout << endl;
	}
		
}
	


int main(){
	
	int a;
	cout << "Introduza um numero impar de 1 a 15" << endl;
	cin >> a;
	while( (a%2 == 0) || (a > 15) || (a < 1) ){
		cout << "Introduza um numero impar de 1 a 15" << endl;
		cin >> a;		
	}
	desenhaX(a);
}
