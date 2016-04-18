#include <iostream>
using namespace std;

char letra;

int main(){
	cout << "Introduza 1 letra\n";
	cin >> letra;	
	
	cout << "letra | Dec.\n";
	cout << "    " << letra << " | " << int(letra) << endl; 
	letra=letra+1;
	cout << "    " << letra << " | " << int(letra) << endl; 
	letra=letra+1;
	cout << "    " << letra << " | " << int(letra) << endl; 
	letra=letra+1;
	cout << "    " << letra << " | " << int(letra) << endl; 
	letra=letra+1;
	cout << "    " << letra << " | " << int(letra) << endl; 
}
