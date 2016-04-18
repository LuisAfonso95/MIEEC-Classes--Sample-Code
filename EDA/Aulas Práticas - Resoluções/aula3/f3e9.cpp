  
  #include <iostream>
  using namespace std;
  
  char letras[2];

  
  int main (){
	
	cout << "Introduza 2 letras minusculas\n";
	cin >> letras[0] >> letras[1];
	
	//Para as variaveis das letras serem escrito mais rapido

	
	//Este primeiro if verifica se ambas as letras são minusculas
	while( (letras[0] < 'a') || (letras[0] > 'z')){
		cout << "\nA primeira letra nao e minuscula.";
		cout << "\nPor favor introduza apenas letras minusculas\n"; 
	    cin >> letras[0]; 
	 }
	while( (letras[1] < 'a') || (letras[1] > 'z')){
		cout << "\nA segunda letra nao e minuscula.";
		cout << "\nPor favor introduza apenas letras minusculas\n"; 
	    cin >> letras[1]; 
	 }	 
	 
	 //Estes seguintes verificam qual das letras é maior na tabela de ASCII, que é igual à ordem alfabética
	 if( letras[0] < letras[1] ){
		cout << "\nA suas letras por ordem alfabetica: " << letras[0] << ", " << letras[1] << endl;  
	 }
	 else{
		cout << "\nA suas letras por ordem alfabetica: " << letras[1] << ", " << letras[0] << endl;   
	 }
	 
}
