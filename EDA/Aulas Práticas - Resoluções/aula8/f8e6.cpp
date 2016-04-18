#include <iostream>
using namespace std;

double mediaTab(double tab[], int size);

int leTabDouble(double tab[], int maxtab);

int main(){
	const int MAXTAB = 100;
	double tab[MAXTAB];
	
	
	cout << mediaTab(tab,leTabDouble(tab, MAXTAB)) << endl;
	
	
}

int leTabDouble(double tab[], int MAXTAB){
	int util;
	
	cout << "Quantos numeros ira introduzir?" << endl;
	cin >> util;
	while( (util > MAXTAB) || (util < 0) 
	){
		cout << "Introduza um numero entre 1 e " << MAXTAB << endl;
		cin >> util;
	}

	cout << "Introduza agora os numeros " << endl;	
	for(int i=0; i <util; i++){
		cin >> tab[i];
	}
	
	return(util);
}

double mediaTab(double tab[], int size){
	
	double media=0;
	
	for(int i=0; i < size; i++){
		media = media + tab[i];
	}
	media = media / size;
	
	return(media);	
}
