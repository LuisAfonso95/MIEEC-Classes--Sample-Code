#include <iostream>
#include <string>
using namespace std;

void desenhaPiramide(char a){
	int size = a - 'A';
	cout << size << endl;
	
	
	
	for(int i = size-1; i >= 0; i--){
	
		/*for(int k = 0; k <= ((size)*2); k++){
			
				if (k <= size){
					char cenas=  a-(size-k);
					cout << cenas;
				}
				else if (k> size){
					char cenas =  a+(size-k);
					cout << cenas;	
				}
				else{
					cout << " ";
				}
		}*/
		cout << endl;
	}
}
			

int main(){
	char a;
	cin >> a;
	desenhaPiramide(a);
}
