
#include <iostream>
using namespace std;

int i;

int main (){
	cout << "Introduza 1 numero inteiro\n";
	cin >> i;
	
	i = (i < 0) ? -i : i ; 
	
	cout <<"\nO modulo do numero introduzido e: " << i << endl;
}
