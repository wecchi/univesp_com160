/* Videoaula 5 -  21:10
  *  Teste da classe pilha (Stack)
  */

#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    ItemType letra;
    Stack pilha;
    ItemType itemPilha;

    // Inserção dos dados na pilha
    cout << "Insert a string to vetorize: ";
    cin.get(letra);
    while (letra != '\n')
    {
        pilha.push(letra);
        cin.get(letra);
    }

    // Imprimir a pilha (na sequencia do vetor)
    pilha.print();  

    // Leitura dos dados da pilha (vai inverter o texto)
    while (!pilha.isEmpty())
    {
        itemPilha = pilha.pop();
        cout << itemPilha;
    }
    cout << endl;



    return 0;
}