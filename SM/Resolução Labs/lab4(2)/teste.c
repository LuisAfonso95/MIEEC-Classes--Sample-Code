#include <stdio.h>
#include "pcsound.h"












int main (){
    
    unsigned int y;
    printf("Insira a freq : ");
    scanf("%u",&y);
    
    if ( y <60) {
         printf ( " O valor da freq tem de ser superior a 60 Hz para ser audivel aos humanos.\n");
         }
    if ( y > 16000){
         printf ("freq maior que 16000Hz não e audivel. \n");
         }
    outportb(0x43,0xB6);
    set_freq(y);   
    printf("on\n");
    sound_on();
   while(!kbhit());
   printf("off\n");
   return (0);
}       
         
