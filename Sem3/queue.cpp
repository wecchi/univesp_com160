 /* Videoaula 9 -  04:26
  * Implementando a classe abstrata para fila (Queue)
  */

 #include "queue.h"
 #include <iostream>

 using namespace std;

 // Construtor da fila - inicializa os ponteiros como nulo, isso permite usar o "NULL" como critério de parada em algum laço
 Queue::Queue(){
     front = NULL;
     rear = NULL;
 }

 // Destrutor da fila - Apaga o elemento do início para o final da fila, por isso a alteração do front para front->next
 Queue::~Queue(){
     NodeType* tempPtr;
     while (front!= NULL)
     {
        tempPtr = front;
        front = front->next;
        delete tempPtr;
     }
     rear = NULL;   // Para garantir que o ponteiro que aponta para o "final da fila" seja destruído
 }

 // Verificação de fila cheia - o limite aqui seria o espaço em memória (tentamos alocar mais um nó, se não houver erro, então retorna false)
 bool Queue::isFull() const{
     NodeType* location;
     try{
         location = new NodeType;
         delete location;
         return false;
     } catch(bad_alloc exception) {
         return true;
     }
 }

 // Verificação de fila vazia - isto significa que o 1º elemento é nulo (assumindo por conseguinte que o rear também está nulo)
 bool Queue::isEmpty() const{
     return (front == NULL);
 }


// Inserindo elementos - enfileirando um novo elemento na fila
void Queue::enqueue(ItemType newItem){
    if (!isFull()){
        NodeType* newNode;       // Criação e iniciaização de um novo nó
        newNode = new NodeType;
        newNode->info = newItem; // Informação, conteúdo a ser armazenado
        newNode->next = NULL;    // o último da fila possui next = NULL

        // Vamos verificar se a fila está vazia
        if (rear == NULL){
            front = newNode;        // trata-se do primeiro elemento da fila
        } else {
            rear->next = newNode;   // aponta o rear para o novo nó (que agora passa ser o último)
        }
        rear = newNode;            // Designa o último elemento a ser o novo nó (sempre o será)
    } else {
        throw "Queue is already full!";
    }
}

// Retiranto um elemento - desenfileirando o primeiro elemento da fila
ItemType Queue::dequeue(){
    if (!isEmpty()){
        NodeType* tempPtr;  // Criando um ponteiro temporário para o 1º elemento da fila
        tempPtr = front;
        ItemType item = front->info; // Obtém o conteúdo do 1º elemento da fila
        front = front->next;         // Informa que agora o 1º elemento da fila, na verdade é o próximo
        // Se existia apenas um nó na fila, faça com que rear seja NULL, já que só havia uma posição na fila
        if (front == NULL)
            rear = NULL;
        delete tempPtr;
        return item;
    } else {
        throw "Queue is empty";
    }
}

// Imprimindo a lista na saída padrão
void Queue::print() const{
    NodeType* tempPtr = front;          // Obtém o 1º elemento da fila
    cout << "Queue = |";
    while (tempPtr != NULL){
        cout << tempPtr->info << "|";   // Imprime o conteúdo
        tempPtr = tempPtr->next;        // Atritui o ponteiro temporário para o próximo elemento da fila (quando for NULL trata-se do último)
    }
    cout << endl;
}
