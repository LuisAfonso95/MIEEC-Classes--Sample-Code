// SM f8e3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(){}
int BubbleSort(int *v){
	bool organizado; int k = 0;
	do{
		organizado = 1;
		for (int i = 0; i < 5-1; i++){
			if (v[i] > v[i + 1]){
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				organizado = 0;
				k++;
			}
		}
	} while (!organizado);

	return(k);
}
