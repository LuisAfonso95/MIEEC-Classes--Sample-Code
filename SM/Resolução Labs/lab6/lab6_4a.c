#include <stdio.h>

int main(){
	int s2=1, s3=1, s4=2;

	while ((s2>0 && s3<=25) || s4==3){
		printf("$s2=%d, $s3=%d, $s4=%d\n", s2, s3, s4);
		s3++;
		if (s3>25) s4++;
	}
	return 0;
}
