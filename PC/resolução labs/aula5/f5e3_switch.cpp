//===============================================================
// Modificações numa linha de texto
// Autor:      Nome Apelido             Data:2010/mm/dd
// Objectivo:  Exemplificar utilização de do ... while e switch
// Utilizacao: Execute e experimente as várias opções
//=============================================================
#include <iostream>
using namespace std;

string linha; // linha de texto a alterar
char C;       // Operação a realizar

int main() 
{
    cout << "Introduza uma frase:\n";
    getline(cin, linha);

    cout << "\nIntroduza  uma das seguintes letras: m, M ou c"
          << "\nSe pretender respectivamente: "
          << "tranformar em minúsculas, maiúsculas ou codificar.\n"
          << "Responda N se não quiser nenhuma das operações anteriores" << endl;

    do
    {
        cout << "\nNote bem: as opções validas sao: m, M, c ou N! \n";
        cin >> C;
    } while (C != 'm' && C != 'M' && C != 'c' && C != 'N' && C != '.' );

    unsigned int i;  // length() devolve um número sem sinal
    switch (C)
    {
        case 'm': cout << "Em minúsculas\n";
                  i = 0;
                  while(i < linha.length()) 
                  {
                      if(linha[i] >= 'A' && linha[i] <= 'Z') 
                          linha[i] += ('a' -'A');
                      i++;
                  }
		break;
		
                  cout << linha << endl;
        case 'M': cout << "Em maiúsculas\n";
                  i = 0;
                  while(i < linha.length()) 
                  {
                      if(linha[i] >= 'a' && linha[i] <= 'z') 
                          linha[i] += ('A' -'a');
                      i++;
                  }	
                  cout << linha << endl;
		break;
		                  
        case 'c': cout << "Codificando\n";
                  i = 0;
                  while(i < linha.length()) 
                  {
                      linha[i] += 3;
                      i++;
                  }
                  cout << linha << endl;
		break;
		                  
        default:  cout << "Não foi efectuada qualquer operação." << endl;
		break;        
    }
    return(0);
}   
