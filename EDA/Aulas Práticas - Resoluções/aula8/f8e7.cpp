#include <iostream>
using namespace std;

const int DIM_MAX = 5;

void adicionaMatrizes(const float a[][DIM_MAX], const float b[][DIM_MAX],
						float soma[][DIM_MAX], int nlin, int ncol);
						
void multiplicaMatrizes(const float a[][DIM_MAX], const float b[][DIM_MAX],
						float prod[][DIM_MAX],
						int nlin_a, int ncol_a, int ncol_b);
						
int main(){
	const int nlin_a = 2;
	const int ncol_a = 5;
	const int ncol_b = 5;
	
	float soma[nlin_a][ncol_a];
	float prod[nlin_a][ncol_b];
	const float a[nlin_a][ncol_a] = {{1,2,3,4,5},{1,2,3,4,5}};
	const float b[ncol_a][ncol_b] = {{5,9,3,2,1},{5,4,3,2,1}};

	//adicionaMatrizes(a, b, soma, nlin_a, ncol_b);
	multiplicaMatrizes(a, b, prod, nlin_a, ncol_a, ncol_b);
}

void multiplicaMatrizes(const float a[][DIM_MAX], const float b[][DIM_MAX],
						float prod[][DIM_MAX],
						int nlin_a, int ncol_a, int ncol_b){

	for(int k = 0; k < nlin_a; k++){						
		for(int i=0; i< ncol_a; i++){
				for(int col=0; col < ncol_a; col++){	
					prod[k][i]=a[k][i]+b[k][i];
			
		}
	}

}
						
						
						
void adicionaMatrizes(const float a[][DIM_MAX], const float b[][DIM_MAX],
						float soma[][DIM_MAX], int nlin, int ncol){
	
	for(int k = 0; k < nlin; k++){						
		for(int i=0; i<ncol; i++){
			soma[k][i]=a[k][i]+b[k][i];
		}
	}
	
	for(int k = 0; k < nlin; k++){						
		for(int i=0; i < ncol; i++){
			cout << soma[k][i] << ", ";
		}
		cout << endl;
	}
		
							
}
