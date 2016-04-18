#include <stdlib.h>
#include <stdio.h>
#include "PCsound.h"
#include <math.h>
#include <time.h>



int main()
{
char letra;
	
	//do grave
	int freq_do;
	int n_do=-9; 
	freq_do = 440 * pow(pow(2,(1.0/12)), n_do);
	//re
	int freq_re;
	int n_re = -7;
	freq_re =  440 * pow(pow(2,(1.0/12)), n_re);
	
	//mi
	int freq_mi;
	int n_mi = -5;
	freq_mi = 440 * pow(pow(2,(1.0/12)), n_mi);
	
	//fa
	int freq_fa;
	int n_fa = -4;
	freq_fa = 440 * pow(pow(2,(1.0/12)), n_fa);
	
	//sol
	int freq_sol;
	int n_sol = -2;
	freq_sol = 440 * pow(pow(2,(1.0/12)), n_sol);
	
	//la
	int freq_la = 440;
	
	//si
	int freq_si;
	int n_si= 2;
	freq_si = 440 * pow(pow(2,(1.0/12)),n_si);
	
	//do agudo
	int freq_do_agudo;
	int n_do_agudo= 3; 
	freq_do_agudo = 440 * pow(pow(2,(1.0/12)), n_do_agudo);
	
	//f = 2 n/12 × 440 Hz
	
	
	while(1){
while(kbhit()){
letra = getch();
	

		switch(letra)
		{
			case 'a':{set_freq(freq_do);
					 sound_on();
					demora(1);
					
					
					 };continue;
			case 's':{set_freq(freq_re);
					 sound_on();
					demora(1);
					
					 
					};continue;
			case 'd':{set_freq(freq_mi);
					sound_on();
					demora(1);
					
					
					};continue;
			case 'f':{set_freq(freq_fa);
					sound_on();
					demora(1);
					
					
					};continue;
			case 'g':{set_freq(freq_sol);
					sound_on();
					demora(1);
					
					
					};continue;
			case 'h':{set_freq(freq_la);
					sound_on();
					demora(1);
					
					
					};continue;
			case 'j':{set_freq(freq_si);
					sound_on();
					demora(1);
					
					
					};continue;
			case 'k':{set_freq(freq_do_agudo);
					sound_on();
					demora(1);
					
					
					};continue;
			case '*':continue;
			default: break;
			
			
			
		}
}
sound_off();		
		
	
}
}