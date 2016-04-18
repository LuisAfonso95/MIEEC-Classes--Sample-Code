#include "frac.h"
#include <iostream>
using namespace std;

struct frac fraccao(int numerador, int denominador){
	struct frac fraccao;
	
	fraccao.num = numerador;
	fraccao.den = denominador;
	
	return (fraccao);
}

void mostra(struct frac fraccao){
	
	cout << fraccao.num << "/" << fraccao.den << endl;
	
}

struct frac soma (struct frac a, struct frac b){
	struct frac soma;

	
	soma.num = (a.num*b.den) + (b.num*a.den);
	soma.den = (a.den*b.den);
	
	return(soma);
		
}

struct frac somamult(struct frac somas[], int size){
	
	for(int i = 1; i < size; i++){
		somas[i]= soma(somas[i],somas[i-1]);
	}
	
	return(somas[size-1]);
	
	
}

void irred (int &a, int &b){
	int c;
	int a2, b2;
	a2=a;
	b2=b;
	while( (a%b) != 0 ){
		c= a2%b2;
		a2=b2;
		b2=c;		
	}
	a= a/b2;
	b = b/b2;
		
}

void irredutivel( struct frac & entrada){
	int c;
	int a2, b2;
	bool sinal = 0;  // por omissão o sinal é positivo
	
	if (entrada.den==0){
		return;
	}
	
	if ( (entrada.num > 0 ) && (entrada.den > 0) ){
		a2 = entrada.num;
		b2 = entrada.den;
	}
	else{
		
		if(entrada.num < 0){
			a2 = (-1) * entrada.num;
			sinal^=1;
		}
		if( entrada.den < 0){
			b2 = (-1) * entrada.den;
			sinal^=1;
		}
	}
	
	if( a2 > b2){
		irred(a2,b2);
	}
	else{
		irred(b2,a2);
	}
	entrada.num= a2;
	entrada.den = b2;
	
	if (sinal == 1){
		entrada.num=entrada.num * (-1);
	}
		
		
}

void reduzir( struct frac reduz[], int size){
	
	for(int i=0; i < size; i++){
		irredutivel(reduz[i]);
	}
	
}

bool fracigual(struct frac a, struct frac b){
	bool igual;
	
	irredutivel(a);
	irredutivel(b);
	
	if( (a.den == b.den) && (a.num == b.num) ){
		igual=1;
	}
	else{
		igual=0;
	}
		
	return(igual);	
}

int mdc(int a, int b){
	struct frac a2;
	int maxdiv;
	
	a2.num=a;
	a2.den=b;
	
	
	irredutivel(a2);
	
	maxdiv= a/a2.num;
	
	return(maxdiv);
	
	
	
}
	
struct frac divisao( const struct frac &a, const struct frac &b){
	struct frac div;
	struct frac a2, b2;
	irredutivel(a2);
	irredutivel(b2);
	
	div.num= a2.num*b2.den;
	div.den= a2.den*b2.num;
	
	return(div);

}
