#include <iostream>
using namespace std;

bool controlo=0;
char letra;

int main(){
	cout << "\nIntroduza uma maiuscula\n";  
	cin >> letra;
	while(controlo!=1){
		if( (letra >= 'A') && (letra <='Z') ){
			controlo=1;
		}
		else{
			cout << "\nIntroduza apenas uma maiuscula se faz favor \n";
			cin >> letra;
		}
	}
	
	letra=letra+('a'-'A');
	cout << letra << endl;
	
	
		
}
