#include <iostream>
using namespace std;

const float PI = 3.1416;

float pede_real_pos(const char msg[], const char msg_erro[]);
float area_esfera(float raio);

int main(){
	
	const char pede_raio[] = "De-me a medida do raio de uma esfera (>0): ";
	const char erro_raio[] = "A medida do raio nao pode ser nula ou negativa! ";
	
	int raio = pede_real_pos(pede_raio, erro_raio);
	cout << "Area = " << area_esfera(raio) << endl;
	
	return(0);

}

float pede_real_pos(const char msg[], const char msg_erro[]){
	float positivo;
	
	do{
		cout << msg;
		cin >> positivo;
		
		if (positivo <= 0){
			cout << msg_erro << endl;
		}
	}while(positivo<=0);
	
	return(positivo);
}

float area_esfera(float raio){
	float area;
	area= 4 * PI * (raio * raio);
	
	return(area);
	
}

