
//===================================================
// Apresenta os multiplos de 3 \in [1.. n], n > 3
//
// Autor: Nome Apelido
//Data:2011/mm/dd
//
// Objectivo: estudar o alcance/ambito das variaveis
//
//incluindo um ciclo do while
//===================================================

#include <iostream>
using namespace std;
int n = 2; // n e’ uma variavel global


int main(){
	int n = 0;
	do {
		// Nova variavel muito local. Torna o ’n’ global invisivel.
		cout << "De um inteiro maior do que 3: ";
		cin >> n;
		if (n <= 3) cout << "Valor Invalido. Tente de novo." << endl;
	} while ( n <= 3 ); // Este n e’ o muito local ou o global?
	
	cout << "\nVou mostrar os multiplos de 3 <= " << n << endl;
	
	int i; // Contador (variavel) local
	
	for (i=1; 3*i <= n; ++i)
		cout << 3*i << endl;
		
	return(0);
}
