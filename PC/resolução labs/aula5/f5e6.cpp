#include <iostream>
using namespace std;

int m, t;
float s, p;

int main (){
	
	cout << "Introduza um numero de 2 a 9\n";
	cin >> m;
	
	while( (m < 2) || (m > 9) ){
		cout << "Apenas numeros de 2 a 9, se faz favor\n";
		cin >> m;
	}
	
	s =0;
	for(int w = 1; w <= (m+1); w++){
		p = 1;
		for(int i = 0; i <= w; i++){
			p *=(5 + w + 2 * i);
		}
		s += w * p;
	}
	
	cout << p << endl;
	
}
