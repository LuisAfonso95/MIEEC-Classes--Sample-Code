#include <stdlib.h>
#include <stdio.h>
#include "PCsound.h"
#include "leitor.h"
#include "vector.h"
#include "leFichMusica.h"



int main () { 



int i,j;
/*int valor;*/
vector_t *a,*b;

int size = leFichMusica ("beethoven_sinf9.txt",&a,&b); 


vector_prune(a,29);
vector_prune(b,29);

char key;

vector_t *a2,*b2;
for(i=0; i<6; i++) {
	
a2 = vector_split(a,4);	//a2 agora tem de 0 a 24, e o a de 0 a 4
b2 = vector_split(b,4); //b2 agora tem de 0 a 24, e o a de 0 a 4

for(j=0; j<5;j++){

		set_freq(vector_get(a,j));
		sound_on();
		demora(vector_get(b,j));


}
sound_off();
printf("Continua? (C)\n");
key = getchar();

if (key != 'c') break;

}


/*
	
		set_freq(vector_get(a,i));
		sound_on();
		demora(vector_get(b,i));
		}
	else if(valor == 0){
		sound_on();
		demora(1);
		}
	else if(valor ==-1){
		sound_off();
		demora(1);
		}
}*/
		
}