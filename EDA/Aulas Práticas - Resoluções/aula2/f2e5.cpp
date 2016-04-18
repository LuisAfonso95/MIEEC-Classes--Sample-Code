#include <iostream>
using namespace std;

char letras[5];

int main(){
	cout << "Introduza 1 letra\n";
	cin >> letras[0];
	letras[1]=letras[0]+1;
	letras[2]=letras[0]+2;
	letras[3]=letras[0]+3;
	letras[4]=letras[0]+4;
	
	cout << "letra | Dec.\n";
	cout << "    " << letras[0] << " | " << int(letras[0]) << endl; 
	cout << "    " << letras[1] << " | " << int(letras[1]) << endl; 
	cout << "    " << letras[2] << " | " << int(letras[2]) << endl; 
	cout << "    " << letras[3] << " | " << int(letras[3]) << endl; 
	cout << "    " << letras[4] << " | " << int(letras[4]) << endl; 
}
