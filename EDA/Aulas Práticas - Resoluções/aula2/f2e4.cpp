#include <iostream>
using namespace std;

float lado1, lado2;

int main(){
	cout << "Este programa permite calcular a área de um rectângulo em cm\n";
	
	cout << "Introduza o 1º lado do rectângulo\n";
	cin >> lado1;
	
	cout << "\nIntroduza agora 2º lado do rectângulo\n";
	cin >> lado2;
	cout << "\nUm rectângulo de " << lado1 << "*" << lado2 << " tem área: " << lado1*lado2 << "cm2" << endl;
		
}
