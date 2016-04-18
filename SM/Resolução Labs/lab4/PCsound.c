#include <stdlib.h>
#include <stdio.h>
#include "PCsound.h"
#include <time.h>


void set_freq(unsigned int freq){
unsigned int count;
count = 1193180UL / freq;
outportb(0x42,count);
outportb(0x42,count>>8);
}




void sound_on(){
unsigned char anterior;
anterior=inportb(0x61);
outportb(0x61, anterior | 0x03 ); /* qual o valor ?? 0x03 para colocar os bits 0 e 1 do porto 0x61 a 1*/
}

void sound_off(){
unsigned char anterior;
anterior=inportb(0x61);
outportb(0x61, anterior & 0xFC); /* qual o valor ?? 0xFC para colocar os bits 0 e 1 do porto 0x61 a 0*/
}


void demora(int secs){
 time_t inicial, final;

 inicial = time(NULL);
 final = inicial;
 while (difftime(final,inicial)< secs){
 final = time(NULL);
 }
 }