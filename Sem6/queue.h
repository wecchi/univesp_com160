 /* 
  * Definindo o tipo abstrato de dados para a fila
  */
#ifndef QUEUE_H 
#define QUEUE_H 
    #include "node_type.h"

    class Queue{
        public:
            Queue();    // Construtor
            ~Queue();   // Desrtutor
            bool isEmpty() const;   // Fila cheia?
            bool isFull() const;    // Fila vazia?
            void print() const;     // Exibe os elementos da fila
            
            void enqueue(ItemType); // Enfileirar, isto é, inserir um novo item
            ItemType dequeue();     // Desenfileirar, isto é, retirar o 1º da fila

        private:
            NodeType* front;    // Ponteiro para o 1º da fila
            NodeType* rear;     // Ponteiro para o último item da fila

    };

#endif

