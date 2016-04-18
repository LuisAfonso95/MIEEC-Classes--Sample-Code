

#include <iostream>
using namespace std;
  
  
float n [6];
int main (){
	
	cout << "\nIntroduza 6 numeros reais\n";  
	
	for (int i=0 ; i < 6 ; i++){
		cin >> n[i];
	}  
	
	cout << "\n Os numeros por ordem inversa sao:\n";
	cout << n[5];
	for(int i=4 ; i >= 0 ; i--){
		cout << ", " << n[i] ;
	}
	cout << endl;
}

//A tabela tem uma dimensão minima mínimo de 6 
