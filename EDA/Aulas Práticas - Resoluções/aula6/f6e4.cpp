#include <iostream>
#include <cfloat>
#include <cmath>

using namespace std;

float hipotenusa(float a, float b);
float leftfloat();

int main(){
	float c1, c2;
	
	cout << "\nIntroduza o primeiro cateto ";
	c1 = leftfloat();
	cout << "\nIntroduza o segundo cateto ";	
	c2 = leftfloat();


	cout << "A hipotenusa de um triangulo " << c1 << " por " << c2 << " e " << hipotenusa(c1,c2) << endl;
	
}

float hipotenusa(float a, float b){
	float soma;
	float hipot;
	
	soma = (a * a) + (b * b);
	hipot = sqrt(soma);
	
	return(hipot);
	
	
}

float leftfloat(){
	int v;
	
	do{
		cout << "\nIntroduza um valor estritamente positivo \n";
		cin >> v;
	}while(v <= 0);	
	
	return(v);
}
