 /* Videoaula 8 -  04:45
  * Definindo o tipo abstrato de dados para pilha
  */

 #include "itemtype.h"

 class Stack{
     public:
        Stack();    // Construtor
        ~Stack();   // Desrtutor
        bool isEmpty() const;
        bool isFull() const;
        void print() const;
        void push(ItemType);
        ItemType pop();

    private:
        NodeType* structure;

 };