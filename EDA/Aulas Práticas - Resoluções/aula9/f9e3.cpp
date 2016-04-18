#include <iostream>
#include <string>
using namespace std;


struct tempo{
	int hora; // 0-23
	int minuto; // 0-59
	int segundo; // 0-59
};

struct tempo convertetempo(int hora, int min, int sec){
	struct tempo tempo;
	
	tempo.hora=hora;
	tempo.minuto=min;
	tempo.segundo=sec;
	
	return(tempo);
}

void mostraTempo(const struct tempo & dado){
	
	cout << dado.hora << "h" << dado.minuto << "m" << dado.segundo << "s" << endl;
	
}

bool somaTempo(struct tempo & soma, const struct tempo & parcela){
	int tempsec;
	int tempmin;
	bool acima24;
	
	if( (soma.segundo+parcela.segundo) < 60){
		soma.segundo=soma.segundo+parcela.segundo;	
		tempsec=0;
	}
	else{
		soma.segundo=soma.segundo+parcela.segundo-60;
		tempsec=1;
	}
	
	if( (soma.minuto+parcela.minuto+tempsec) < 60){
		soma.minuto=soma.minuto+parcela.minuto+tempsec;	
		 tempmin = 0;
	}
	else{
		soma.minuto=soma.minuto+parcela.minuto+tempsec-60;
		 tempmin=1;
	}

	if( (soma.hora + parcela.hora + tempmin) < 24){
		soma.hora = soma.hora + parcela.hora + tempmin;	
		acima24=0;
	}
	else{
		soma.hora = soma.hora + parcela.hora + tempmin-24;
		acima24=1;	
	}
	
	
	return(acima24);	
	
}

int main(){
	
	struct tempo dado;
	struct tempo parcela;
	int hora, minuto, segundo;
	
	cin >> hora >> minuto >> segundo;
	dado = convertetempo(hora, minuto, segundo);
	cin >> hora >> minuto >> segundo;
	parcela = convertetempo(hora, minuto, segundo);
	
	bool acima24 = somaTempo(dado, parcela);
	cout << acima24 << endl;
	mostraTempo(dado);
	
	
	
	
}
