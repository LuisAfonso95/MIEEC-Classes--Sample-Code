#include <iostream>
#include <string>
using namespace std;

char linha1[80];
string linha2;

int main(){
	cout << "Introduza a primeira linha\n";
	cin.getline (linha1,80);
	cout << "Introduza a segunda linha\n";
	//cin.ignore(1000,'\n');
	//cin.ignore();
    getline (cin,linha2);
	
	cout << "\nPrimeira linha: \"" << linha1 << "\"\n"; 
	cout << "\nSegunda linha: \"" << linha2 << "\"\n";
}
