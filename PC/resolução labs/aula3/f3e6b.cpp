  
  #include <string>
  #include <cstring>
  #include <iostream>
  using namespace std;
  
  char frase[200];
  int i = 0;
  int k = 0;
  
  int main (){
	
	cout << "\nIntroduza uma frase ate 200 characteres\n";
	cin.getline (frase,sizeof(frase)); 
	
	i=0;
	while(i < int(strlen(frase))){					//Loop enquanto i < 200
		if(frase[i]== ' '){		//Verifica se se algum caracter é 1 espaço
			k++;						//Se algum for um espaço incrementa k
		}
		i++;							//incrementação de i para ler os varios caracteres da string
	}
	
	
	cout << "\nA sua frase tinha "<< k << " espacos\n";
}
