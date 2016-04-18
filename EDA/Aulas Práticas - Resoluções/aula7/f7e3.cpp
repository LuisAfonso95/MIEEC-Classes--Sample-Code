#include <iostream>
using namespace std;

const float PI = 3.1416;

float pede_real_pos(const char [], const char []);
void area_volume_esfera(float, float &, float &);
float area_volume_esfera(float , float &);






int main(){
	const char pede_raio[] = "De-me a medida do raio de uma esfera (>0): ";
	const char erro_raio[] = "A medida do raio nao pode ser nula ou negativa!\n";	
	
	float raio, area, volume;
	raio = pede_real_pos(pede_raio, erro_raio);
	
	//1ª função, area e volume com memoria partilhada
	area_volume_esfera(raio, volume, area);
	cout << "\nPrimeira funcao, area e volume com memoria partilhada" << endl;
	cout << "Uma esfera de raio " << raio << " tem area " << area << " e volume " << volume << endl << endl;
	//2ª função, area partilhada, devolve volume
	volume = area_volume_esfera(raio, area);
	cout << "Segunda funcao, area partilhada, devolve volume" << endl;		
	cout << "Uma esfera de raio " << raio << " tem area " << area << " e volume " << volume << endl;
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



void area_volume_esfera(float raio, float &v, float &a){
	a= 4 * PI * (raio * raio);	
	v = (a * raio) / 3;
}

float area_volume_esfera(float raio, float &a){
	float v;
	a= 4 * PI * (raio * raio);	
	v = (a * raio) / 3;
	return(v);
}


