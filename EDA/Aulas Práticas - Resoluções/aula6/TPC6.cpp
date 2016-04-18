#include <iostream>

using namespace std;

void trianguloX2(int size);

int main(){
	int x;

	cout << "Introduza um valor entre 2 e 40\n";	
	cin >> x;
	
	while( (x < 2) || (x > 40) ){
		cout << "Introduza um valor entre 2 e 40\n";
		cin >> x;
	}	
	
	trianguloX2(x);
	
	
}

void trianguloX2(int size){
	
	for(int i = 1; i <= size; i++){
		//1ª, 2ª e ultima linha
		if( (i <= 2) || (i == size) ){
			for(int k=1; k <= size; k++){
				if(k > (size-i)){
					cout << 'x';
				}
				else{
					cout << ' ';
				}
			}
		}
		//todas as outras linha		
		else{
			for(int k=1; k <= size; k++){
				if( (k == size) || (k == (size - (i-1))) ){
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

