 /* Videoaula 6 -  16:18 
  *  Teste do uso da classe queue (estrutura fila)
  */
#include "queue.h"
#include <iostream>

using namespace std;

 int main(){
     char letra;
     Queue fila;
     char letraNaFila;

     // Inserção dos dados na fila
    cout << "Insert a string to vetorize: ";
    cin.get(letra);

    while(letra != '\n' and !fila.isFull()) {
        fila.enqueue(letra);
        cin.get(letra);
    }

    // Imprimindo a fila
    fila.print();

    // Desenfileirando os dados
    while (!fila.isEmpty())
    {
        letra = fila.dequeue();
        cout << letra;
    }
    cout << endl;    

     return 0;
 }