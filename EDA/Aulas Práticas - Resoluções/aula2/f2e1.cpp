  //===================================================
  // Caracteres e inteiros                    
  // Autor: Nome Apelido               Data:2013/mm/dd
  // Objectivo:  Calculando e mostrando caracteres
  // Utilizacao: Execute que as mensagens aparecem
  //===================================================
  
  #include <iostream>
  using namespace std;
  
  // O tipo char ocupa 8 bits. Por omisão,
  // se interpretado como um valor numérico, tem sinal (de -128 a +127)
  // Mas podemos definir unsigned char 
  // e nesse caso o valor numérico é (de 0 a 255)
  
  char letra1, letra2, letra3, letra4;
  int  codigo;
  
  int main()
  {
     letra1 = 'P';   // Letra P  
     letra2 =  81;   // Código decimal da letra Q (cast implícito)
     letra3 =  0122; // Código octal da letra R (cast implícito)
     letra4 =  0x53; // Código hexadecimal da letra S (cast implícito)
     
     //  Mostra as letras:
     cout << "\nMostra as letras: " << letra1 << letra2  << letra3 
                                    << letra4 << endl;
     
     cout << "\nAs letras e os Códigos:";
     codigo = letra2 ;   // Cast implícito de char para int
     cout << "\nA letra \'"<< letra1 << "\' tem código ASCII " << int(letra1);
     cout << "\nA letra \'"<< letra2 << "\' tem código ASCII " << codigo;
     cout << "\nA letra \'"<< letra3 << "\' tem código ASCII " << letra3 + 0;   
     cout << "\nA letra \'"<< letra4 << "\' tem código ASCII " << 0x53;   
     
     // Passando para as letras seguintes do alfabeto
     letra1 = letra3 + 1; // Cast implícito
     letra2 = letra1 + 1; // Cast implícito
     letra3 = letra2 + 1; // Cast implícito
     
     cout << "\n\nNovamente as letras e os Códigos:";
     codigo = letra2 ;   // Cast implícito de char para int
     cout << "\nA letra \'"<< letra1 << "\' tem código ASCII " << int(letra1);
     cout << "\nA letra \'"<< letra2 << "\' tem código ASCII " << codigo;
     cout << "\nA letra \'"<< letra3 << "\' tem código ASCII " << letra3+0;  
     cout << endl;            
     return(0);
  } 
