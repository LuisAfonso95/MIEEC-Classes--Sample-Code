#include <iostream>
using namespace std;



int main(){
	unsigned char flags;
	flags= 0x44;
	cout << ((flags &= 0x02)==0x02) << endl;
	
	flags |= 0x04;
	flags ^= 0x01;
	
	
	flags = 0x07; //0000 0111

	flags <<= 2; //dá 0001 1100
	flags >>= 1; //dá 0000 0011

	
}
