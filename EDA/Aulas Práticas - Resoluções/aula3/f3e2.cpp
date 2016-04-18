  
  
  #include <iostream>
  using namespace std;
  
  float x, y;
  
  int main (){
	  
	  cout << "\nIntroduza 1 numero real\n";
	  cin >> x;
	  cout << "\nIntroduza 2 numero real\n";
	  
	  cin >> y;
	  if (x<y){
		cout << "\nOs numeros por ordem crescente: " << x << ", " << y << endl;
	  }
	  else{
		cout << "\nOs numeros por ordem crescente: " << y << ", " << x << endl;
	  }
  }
