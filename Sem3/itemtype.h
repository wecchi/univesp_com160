 /* Videoaula 8 -  01:00
  * Definindo o tipo do item a se colocado na pilha, neste caso será um char
  * E a estrutura usada para guardar a informação e o endereço do próximo elemento
  */

#ifndef ITEMTYPE_H   // Inclua esse bloco apenas se ITEMTYPE_H não está definido
#define ITEMTYPE_H   // Na primeira inclusão, defina ITEMTYPE_H para que este bloco não seja incluído mais de uma vez.

  typedef char ItemType;

  struct NodeType
  {
      ItemType info;
      NodeType* next;
  };
#endif