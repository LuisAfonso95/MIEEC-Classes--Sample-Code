
#include <iostream>
using namespace std;

float k[12];
float r[2];
int indice[2];


int main(){
	
	cout << "\nIntroduza 12 numeros reais\n";  
	for (int i=0 ; i < 12 ; i++){
		cin >> k[i];
	} 

	r[0]=k[0];
	r[1]=k[0];
	
	int m = 0;
	while(m<12){
		if(k[m]<r[0]){
			r[0]=k[m];
			indice[0]=m;
		}
		
		if(k[m]>r[1]){
			r[1]=k[m];
			indice[1]=m;
		}
		m++;
	}


	cout << "Os numero menor e " << r[0] << " com indice " << indice [0] << endl;
	cout << " e o maior e " << r[1] << " com indice " << indice[1] << endl;	
	
}

