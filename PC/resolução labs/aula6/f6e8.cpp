
//=======================================================
// Mostrar os divisores de um numero
//
// Autor: Nome Apelido
//Data:2011/mm/dd
//
// Objectivo: estudar o alcance de variaveis
//
//declaradas dentro de ciclos
//=======================================================
#include <iostream>

using namespace std;

int main()
{
	int n;
	do{
		cout << "De um inteiro positivo: ";
		cin >> n;
		if (n < 0)
			cout << "Valor negativo. Tente de novo." << endl;
		else if (n == 0)
			cout << "Valor nulo. Tente de novo." << endl;
	} while (n <= 0);
	
	for (int div = 1; div <= n; ++div){
		
		if ( (n % div) == 0 ){
			cout << "\n" <<  div << "e’ divisor de " << n << endl;
		}
	}
	
	
	cout << "\nEste ciclo termina quando " << "div"
	<< " e’ igual a " << n+1;
	
	return(0);
}
