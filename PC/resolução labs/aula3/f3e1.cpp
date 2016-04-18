  
  
  #include <iostream>
  using namespace std;
  
  float x, y;
  
  int main (){
	  
	  cout << "\nIntroduza 1 numero real\n";
	  cin >> x;
	  cout << "\nIntroduza 2 numero real\n";
	  
	  cin >> y;
	  if (x<y){
		cout << "\nO maior numero e: " << y << endl;
	  }
	  else{
		cout << "\nO maior numero e: " << x << endl;
	  }
  }
