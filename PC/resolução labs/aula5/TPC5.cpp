#include <iostream>
using namespace std;

char a, b;
int i;
bool r;

int main(){
	cout << "Introduza 2 caracteres diferentes\n";
	cin >> a >> b;
	
	while(a == b){
		cout <<	"Por favor introduza um caractere diferente de " << a << endl;
		cin >> b;
	}
	
	cout << "\nAgora introduza 1 inteiro\n";
	cin >> i;
	while( ((i % 2) != 0) || (i < 4) || (i >40) ){
		cout <<	"O numero tem de ser par de 4 a 40\n";
		cin >> i;
	}		
	
	for(int k = 0; k <=i; k++){
		r^=1;
		for(int j = 0; j <=i; j++){
			if((j % 2) == r) {
				cout << a;
			}
			else{
				cout << b;
			}
		}
		cout << endl;
	}
	
	
	
}
