#include <iostream>
using namespace std;

int fatorial(int valor);

int main(){
	int val;
	
	cin >> val;
	
	int f = fatorial(val);
	
	if (f==0){
		cout << "Erro, foi introduzido um valor nao positivo" << endl;
	}
	else{
		cout << f << endl;
	}

}


int fatorial(int valor){
	int resultado;
	int i;
	
	if(valor<=0){
		resultado=0;
	}
	else{	
		i=valor;
		resultado = 1;
	
		while(i >= 1){		
			resultado=resultado * i--;
		}
	}	
	return(resultado);
}


