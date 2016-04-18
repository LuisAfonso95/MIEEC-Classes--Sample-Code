
#include <iostream>
#include <cfloat>

using namespace std;

float calculadora(char operacao, float a, float b);

int main(){
	float a, b;
	char c;
	
	cout << "Para parar o programa introduza '.'\n";
	
	do{
		cout << "Introduza primeiro o operador\n";
		cin >> c; 
		
		if (c != '.'){
			if( (c == '+') || (c == '-') || (c == '*') || (c == '/') ){
				cout << "Introduza 2 numeros\n";
				cin >> a >> b;
				cout << a << c << b << '=' << calculadora(c, a, b) << endl;
			}
			else{
				cout << "Introduza um operador válido\n";
			}
		}
		
	}while(c != '.');
	
	
}


float calculadora(char operacao, float a, float b){
	float resultado;
	
	switch(operacao){
		
		case '+':
			resultado=a+b;
			break;
			
		case '-':
			resultado=a-b;
			break;
		
		case '*':
			resultado=a*b;
			break;
		
		case '/':
			if(b != 0){
				resultado=a/b;
			}
			else{
				if (a > 0){
					resultado=FLT_MAX;
				}
				else if (a < 0){
					resultado=FLT_MIN;
				}
				else if (a == 0){
					resultado=0;
				}
			}	
			break;
			
		}
		
	return(resultado);
}	
