 /* Videoaula 8 -  01:00
  * Definindo o tipo do item a se colocado na pilha, neste caso será um char
  * E a estrutura usada para guardar a informação e o endereço do próximo elemento
  */

typedef char ItemType;

struct NodeType
{
    ItemType info;
    NodeType* next;
};
