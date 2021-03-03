 /* Videoaula 5 -  06:03 
  *  Criando uma classe abstrata para a estrutura de pilha
  */
#include "itemtype.h"

const int MAX_ITEMS = 100;

class Stack {
    private: // seção privada
        // Membros privados
        int lenght;
        ItemType* structure;

    public: // seção pública
        Stack();    //Construturor - Cria uma instância do objeto (chamado pelo new)
        ~Stack();   // Destrutor - Desaloca a memória para o objeto (chamado pelo delete ou quando a variável sair do escopo)
        bool isEmpty() const;
        bool isFull() const;
        void print() const;
        void push(ItemType);
        ItemType pop();

};