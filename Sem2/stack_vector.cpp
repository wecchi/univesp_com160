 /* Videoaula 5 -  15:10
  *  Implementação da pilha através de vetor
  */

#include "stack.h"
#include <iostream>

using namespace std;

Stack::Stack(){
    // Alocação dinâmica do vetor no construtor
    lenght = 0;
    structure = new ItemType[MAX_ITEMS];
}

Stack::~Stack(){
    delete [] structure;
}

bool Stack::isEmpty() const{
    return (lenght == 0);
}

bool Stack::isFull() const{
    return (lenght == MAX_ITEMS);
}

void Stack::push(ItemType item){
    if (!isFull()){
        structure[lenght] = item;
        lenght++;
    } else {
        // invocação de erro ser tratado pelo chamador
        throw "Stack is already full!";
    }
}

// Retorna um elemento do tipo "ItemType"
ItemType Stack::pop(){
    if (!isFull()){
        ItemType aux = structure[lenght-1]; // busca o elemento que está no topo da pilha
        lenght--;
        return aux;
    } else {
        // invocação de erro ser tratado pelo chamador
        throw "Stack is empty!";
    }
}

void Stack::print() const{
    if (!isEmpty()){
        cout << "Stack = |";
        for (int i = 0; i < lenght; i++){
            cout << structure[i] << "|";
        }
    } else {
        cout << "Stack is empty!";
    }
    cout << endl;
}