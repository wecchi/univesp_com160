 /* Videoaula 8 -  06:17
  * Implementado a classe abstrata stack
  */

 #include "stack.h"
 #include <iostream>

  using namespace std;

// Implementando o contrutor - apontando para "nulo" significa não apontar para ninguêm
 Stack::Stack(){
     structure = NULL;
 }

 // Implementando o destrutor
 Stack::~Stack(){
     NodeType* tempPtr;
     while (structure != NULL)
     {
        tempPtr = structure;
        structure = structure->next;
        delete tempPtr;
     }
     
 }

 // Verificação de vazio
 bool Stack::isEmpty() const{
     return (structure == NULL);
 }

 // Verificação de cheio - tenta alocar um novo espaço na memória, se conseguir ainda há memória disponível
 bool Stack::isFull() const{
     NodeType* location;
     try {
         location = new NodeType;
         delete location;
         return false;
     } catch (std::bad_alloc exception) {
        return true;
     }
 }

 // Inserindo elementos - push()
 void Stack::push(ItemType item){
     if (!isFull()){
         NodeType* location;        // Declarando o ponteiro chamado location
         location = new NodeType;   // Inicializando o ponteiro como NodeType
         location->info = item;     // Incluindo o conteúdo recebido na estrutura, elemento info
         location->next = structure;// Informando qual será o próximo item, no caso é o próprio structure
         structure = location;      // faz com que esse structure seja a cabeça da pilha
     } else {
         throw "Stack is already full!";
     }
 }

 // Removendo elementos - pop()
 ItemType Stack::pop(){
     if (!isEmpty()){
         NodeType* tempPtr;
         tempPtr = structure;
         ItemType item = structure->info;
         structure = structure->next;
         delete tempPtr;
         return item;
     } else {
         throw "Stack is empty!";
     }
 }

 // Imprimido a pilha na saída padrão
 void Stack::print() const{
     NodeType* tempPtr = structure;
     cout << "Stack = |";
     while (tempPtr != NULL){
         cout << tempPtr->info << "|";
         tempPtr = tempPtr->next;
     }
     cout << endl;
 }