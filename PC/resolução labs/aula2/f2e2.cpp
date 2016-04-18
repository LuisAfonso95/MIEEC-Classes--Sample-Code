//===================================================
// Caracteres e inteiros, maiúsculas                  
// Autor: Nome Apelido               Data:2013/mm/dd
// Objectivo:  Calculando e mostrando caracteres
// Utilizacao: Execute que as mensagens aparecem
//===================================================

#include <iostream>
using namespace std;

char letra = 'q';
char grande;
 
int main()
{
   //Obtém a maiúscula de letra
   grande = 'A'+ (letra - 'a'); // <=> grande = letra + ('A' - 'a');
   //  Mostra
   cout << "Mostra:\n";
   cout << letra << '\n' << grande << endl;
   
   return(0);
}
