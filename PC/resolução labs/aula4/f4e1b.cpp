

#include <iostream>
using namespace std;
  
  
float n [6];
int main (){
	
	cout << "\nIntroduza 6 numeros reais\n";  
	
	for (int i=0 ; i < 6 ; i++){  
		cin >> n[i];
	}  
	
	cout << "\n Os numeros por ordem inversa sao:\n";
	for(int i=5 ; i >= 0 ; i--){
		cout << n[i] << " ";
	}
	cout << endl;
}
