  
  
  #include <iostream>
  using namespace std;
  
  float x, y;
  int i = 0;
  
  int main (){
	  
	  cout << "\nIntroduza 1 numero real\n";
	  cin >> x;
	  i++;
	  while(x<=0){
		i++;  
		cout << "\nPor favor introduza apenas numeros positivos\n"; 
	    cin >> x; 
	  }
	  
	  cout << "\nIntroduza 2 numero real\n";	  
	  cin >> y;
	  i++;
	  while(y<=0){
		i++;
		cout << "\nPor favor introduza apenas numeros positivos\n"; 
	    cin >> y; 
	  }
	  
	  if (x<y){
		cout << "\nO maior numero e: " << y;
	  }
	  else{
		cout << "\nO maior numero e: " << x;
	  }
	  cout << "\nIntroduziu dados por: " << i << " vezes" << endl;
  }
