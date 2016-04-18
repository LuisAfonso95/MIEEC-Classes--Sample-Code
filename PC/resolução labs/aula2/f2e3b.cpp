

#include <iostream>
using namespace std;

char letra;


int main(){
	cout << "Introduza uma letra maiúscula (A...Z):";
	cin >> letra;
	cout << "\nDigitou \'" << letra << "\' o qual tem o código " << int(letra);
	letra=letra+('a'-'A');
	cout << "\ne a sua minúscula \'" << letra << "\' o qual tem o código " << int(letra) << endl;
}
