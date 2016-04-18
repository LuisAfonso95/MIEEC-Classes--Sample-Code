  
  #include <string>
  #include <iostream>
  using namespace std;
  
  string frase;
  int i = 0;
  int k = 0;
  
  int main (){
	
	cout << "\nIntroduza uma frase\n";
	getline (cin,frase);
	
	while(i <= int(frase.length())){     // loop enquanto i for menor que o tamanho da string
		if(frase[i]== ' '{		 //Se um dos caracteres da string for igual ao espaço
			k++;                         //então incrementa k
		}
		i++;							//incrementação de i para ler os varios caracteres da string
	}
	
	
	cout << "\nA sua frase tinha "<< k << " espacos\n";
}
