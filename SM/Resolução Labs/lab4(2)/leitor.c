#include <stdio.h>
#include "vector.h"
#include "leFichMusica.h"
#include "PCsound.h"

int main(){
	vector_t *nota;
	vector_t *tempo;
	int notas,i;

	
	notas=leFichMusica("beethoven_sinf9.txt",&nota,&tempo);
	for(i=0;i<notas;i++){
		set_freq(vector_get(nota,i));
		sound_on();
		demora(vector_get(tempo,i));
		sound_off();
	}

	return (0);
}
		
	
	

