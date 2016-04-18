#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "pcsound.h"



void demora ( int secs){
     time_t inicial, final;
     inicial = time(NULL);
     final = inicial;
     while (difftime(final,inicial)< secs){
         final = time(NULL);
     }
       }
void set_freq( unsigned int freq){
     unsigned int count;
     count = 1193180UL/freq;
     outportb(0x43,0xB6);
     outportb(0x42,count);
     outportb(0x42,count>>8);
     }
void sound_on(){
     unsigned char anterior; 
     anterior = inportb(0x61);
     outportb(0x61,anterior | 0x03);
     }
void sound_off(){
      unsigned char anterior; 
     anterior = inportb(0x61);
     outportb(0x61,anterior | 0xFC);
     }

    
