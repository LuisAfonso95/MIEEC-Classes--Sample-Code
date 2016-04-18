#include <iostream>


using namespace std;

void trianguloX(int size);
void trianguloN(int size);
	

int main(){
	int x;
	
	cout << "Introduza um valor entre 2 e 9\n";
	cin >> x;
	
	while( (x < 2) || (x > 9) ){
		cout << "Introduza um valor entre 2 e 9\n";
		cin >> x;
	}
		
	trianguloX(x);
	cout << endl;
	trianguloN(x);
}

void trianguloX(int size){
	
	for(int i = 1; i <= size; i++){
		//1ª, 2ª e ultima linha
		if( (i <= 2) || (i == size) ){
			for(int k=1; k <= i; k++){
				cout << 'x';
			}
		}
		//todas as outras linha		
		else{
			for(int k=1; k <= i; k++){
				if( (k == 1) || (k==i) ){
					cout << 'x';
				}
				else{
					cout << ' ';
				}
			}
		}
		cout << endl;
	}
	
}
	
void trianguloN(int size){
	
	for(int i = 1; i <= size; i++){
		//1ª, 2ª e ultima linha
		if( (i <= 2) || (i == size) ){
			for(int k=1; k <= i; k++){
				cout << i;
			}
		}
		//todas as outras linha
		else{
			for(int k=1; k <= i; k++){
				if( (k == 1) || (k==i) ){
					cout << i;
				}
				else{
					cout << ' ';
				}
			}
		}
		cout << endl;
	}
	
}	
	
