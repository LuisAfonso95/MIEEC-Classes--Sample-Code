#include <iostream>
using namespace std;

int k[10];

int main(){
	cout << "\nIntroduza 10 numeros inteiros\n";  
	
	for (int i=0 ; i < 10 ; i++){
		cin >> k[i];
	}  
	for (int i=1 ; i < 10 ; i++){
		k[0]=k[0]+k[i];
	} 
	
	cout << "A media desses numeros e: \n"; 
	cout << int((k[0]/10)+0.5) << endl;
}
