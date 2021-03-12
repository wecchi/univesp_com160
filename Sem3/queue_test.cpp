 /* Videoaula 9 -  15:57
  * Testando  a classe fila (Queue) com lista encadeada
  */

 #include "queue.h"
 #include <iostream>

 using namespace std;

 int main() {
     ItemType letra;        // Captura da letra no teclado
     Queue fila;            // Criação do objeto fila
     ItemType letraFila;    // Letra da fila (queue->info)
     int sequencia = 1;

     // Etapa de enfileiramento
     cout << "Enter a string to enqueue; press return to exit: " << endl;
     cin.get(letra);
     while (letra != '\n'){
        fila.enqueue(letra);
        cin.get(letra);
     }

    // Impressão da fila
     fila.print();

    // Etapa de desenfileiramento
     while (!fila.isEmpty()){
         letraFila = fila.dequeue();
         cout << sequencia << "-" << letraFila << endl;
         sequencia++;
     }

     return 0;
 }