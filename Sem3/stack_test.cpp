/* Videoaula 8 -  18:15
  * Testando a classe stack
  */

 #include "stack.h"
 #include <iostream>

using namespace std;

int main(){
    ItemType letra;
    Stack fila;
    ItemType itemFila;

    // Insere a fila
    cout << "Informe um texto: ";
    cin.get(letra);
    while (letra != '\n'){
        fila.push(letra);
        cin.get(letra);
    }

    // Imprimindo a fila
    fila.print();

    // Remove os items da fila
    while (!fila.isEmpty()){
        itemFila = fila.pop();
        cout << itemFila;
    }
    cout << endl;

    return 0;
}
