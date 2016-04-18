#include <iostream>
using namespace std;

double notas[3];

int main(){
	cout << "Introduza 3 notas\n";
	cin >> notas[0] >> notas[1] >> notas[2];
	cout << "\nMédia: " << int((notas[0]+notas[1]+notas[2])/3+0.5) << endl;
}
