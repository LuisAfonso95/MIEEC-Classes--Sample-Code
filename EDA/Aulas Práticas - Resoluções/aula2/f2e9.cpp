#include <iostream>
using namespace std;

int valores [2];
int main(){
	cout << "Introduza 2 números inteiros\n";
	cin >> valores[0] >> valores[1];
	cout << "\nO resto da divisão entre os 2 dá " << int(valores[0]%valores[1]) << endl;
}
