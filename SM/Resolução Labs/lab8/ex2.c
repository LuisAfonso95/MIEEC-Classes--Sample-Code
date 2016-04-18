#include <stdio.h> 
#include <stdlib.h> 
 


int program_asm(int *tab);
int BubbleSort(int *v);


int main () 
{ 
 	 int tab[5]; 
 	 int i=0;
 	 for (i=0;i<5;i++){
 	 
		 printf ("Introduza o valor numero %d : ", i); 
		 scanf ("%d", &tab[i]); 
	}
	 int k = program_asm(tab);
	 	 
	printf ("O resultado é %d \n",k);  

	 return 0; 
} 
