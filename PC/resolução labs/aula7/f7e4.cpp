#include <iostream>
using namespace std;

double produto_interno(int, double[], double[]);

int main(){
	
//int n;
//cin >> n;

	double u[]={1, 2, 3,9};
	double v[]={3, 4, 5,8};
	
	cout << "vector u = (" << u[0] << ", " << u[1] << ", " << u[2] << ") \n";
	cout << "vector v = (" << v[0] << ", " << v[1] << ", " << v[2] << ") \n";
	cout << "produto interno de u por v = " << produto_interno(4, u, v) << endl;	
	
}

double produto_interno(int k, double u[], double v[]){
	
	int valor = 0;
	
	for (int i = 0; i <= (k-1); i++){
		valor = valor + (u[i] * v[i]);
	}
	return (valor);
	
}
