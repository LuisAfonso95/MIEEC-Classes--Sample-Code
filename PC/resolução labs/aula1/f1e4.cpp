//===================================================
// Calculando o valor de expressões aritméticas                    
// Autor: ...                         Data:2013/mm/dd
// Objectivo:  Calculando e mostrando 
//             o valor de expressões aritméticas             
// Utilização: Execute que as mensagens aparecem
//===================================================
#include <iostream>
using namespace std;

int i, j, k; // Variáveis usadas nos exemplos

int main()
{       
  // Expressões com constantes
  cout << "\n5 * 3 = "  <<  5 * 3 << endl;
  
  // Instrução inútil
  (3 + 1) * 8;  // /===================================================
#include <iostream>
using namespace std;

int i, j, k; // Variáveis usadas nos exemplos

int main()
{       
  // Expressões com constantes
  cout << "\n5 * 3 = "  <<  5 * 3 << endl;
  
  // Instrução inútil
  (3 + 1) * 8;  calcula 32 e passa à instrução seguinte
  
  // Expressões com variáveis 
  i = 7;  // i <-- 7
  j = 3;  // j <-- 3
  // Calcula e mostra, mas não armazena!   
  cout << "\ni * j = "  <<  i * j;      
  // i e j ficaram inalterados
  cout << "\ni = " << i <<  " e  j = " << j<< endl; 
  
  // Atribuicoes
  k = i - j; // Calcula e guarda o resultado em k (k <-- i - j)
  // i e j continuam inalterados
  cout << "\nDepois de k = i - j, i = " << i <<  " e  j = " << j; 
  cout << "\nk = "  <<  k;
  k = k + 1; // k <-- k + 1
  // Mostra k após incremento de um
  cout << "\nDepis de incrementar k = "  <<  k << endl; 
  return(0);
}
