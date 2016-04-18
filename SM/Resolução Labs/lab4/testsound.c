#include <stdio.h>
#include "PCsound.h"

int main(){

unsigned int n;
printf("Insira a freq (Hz): ");
scanf("%u", &n);

if(n==0){
	printf("freq. tem de ser valor inteiro superior a 0. \n");
}

if(n > 20000){
	printf("freq. maior que 20khz (não será audivel).\n");
}

set_freq(n);
printf("ON\n");
sound_on();

while(!kbhit()){} //aguarda o carregar da tecla para parar o som
printf("OFF\n");
sound_off();

return(0);
}
 