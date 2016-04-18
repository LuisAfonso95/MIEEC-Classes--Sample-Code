#include <iostream>
using namespace std;

int factorial (int);

int main(){
	int n;
	int fact=0;
	
	cin >> n;

	cout << factorial(n) << endl;
}


int factorial(int n){

	
	if ( n < 0){
		return(0);
	}
	if (n==0){
		return(1);
	}
	//cout << c << endl;
	// n>=1		
	return(n*factorial(n-1));
	
	
}
