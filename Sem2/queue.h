 /*  Videoaula 6 -  06:23 
  *  Criando uma classe abstrata para a estrutura de dados do tipo fila
  *  é uma estrtura quando precisamos garantir que processos farão acessos aos recursor compartilhados de uma maneira justa:
  *     - documentos enviados para impressão;
  *     - troca de mensagem de um sistema operacional
  */

 #include "itemtype.h"
 const int MAX_ITEMS = 20;

 class Queue
 {
     public:
        Queue();    // Construtor
        ~Queue();   // Destrutor
        bool isEmpty() const;   // A fila está vazia?
        bool isFull() const;    // A fila está cheia?
        void print() const;     // Exiba a fila (estrutura de dados)

        void enqueue(ItemType); // Inclua um item da fila
        ItemType dequeue();     // Retire um item da fila

    private:
        int front;              // posição ou índice do elemento na frente da fila
        int back;               // posição ou índice do último elemento da fila
        ItemType* structure;    // "structure" será implementado como um vetor
 };