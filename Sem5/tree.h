 /* Videoaula 14 -  04:02
  * Contém os dados e os endereços das subárvores (estrurura usada para 
  * guardar a informação e os endereços - ponteiros das subárvores)
  */
#include "aluno.h"
#include <cstddef> // Define vários tipos gerados implicitamente ou usados ​​por certas expressões de linguagem C++

struct NodeType
{
    Aluno aluno;
    NodeType* esquerdo;
    NodeType* direito;
};

/*
  A classe Tree é a que irá gerenciar todas as funções da árvore de busca. Você notará que essa 
  árvore foi implementada com várias funções recursivas privadas e várias funções públicas que simplesmente 
  invocam as funções privadas e fornecem algum valor para o parâmetro como ponto de partida.
 */
class Tree{
    // Interface pública invocando métodos recursivos privados
    public:
        Tree(){root = NULL;}
        ~Tree(){ destroyTree(root);}
        bool isEmpty() const;
        bool isFull() const;
        void retrieveAluno(Aluno &item, bool &found) const{
            retrieveAluno(root, item, found);
        }
        void insertAluno(Aluno item){insertAluno(root, item);}
        void deleteAluno(int ra){deleteAluno(root, ra);}
        void deleteNode(){deleteNode(root);}
        void getSucessor(Aluno &data){getSucessor(root, data);};
        void printPreOrder() const {printPreOrder(root);}
        void printInOrder() const {printInOrder(root);}
        void printPosOrder() const {printPosOrder(root);}

    private:
        // Raiz da árvore binária de busca:
        NodeType* root;

        // Métodos privados que serão invocados pelos métodos públicos:
        void destroyTree(NodeType *&tree);
        void retrieveAluno(NodeType *tree, Aluno &item, bool &found) const; // No caso de 'item' existir, retornará por referência
        void insertAluno(NodeType *&tree, Aluno item); // Ponteiro por referência
        void deleteAluno(NodeType *&tree, int ra);     // Ponteiro por referência
        void deleteNode(NodeType *&tree);
        void getSucessor(NodeType *tree, Aluno &data); // Ponteiro por referência
        void printTree(NodeType *tree) const;
        void printPreOrder(NodeType *tree) const;
        void printInOrder(NodeType *tree) const;
        void printPosOrder(NodeType *tree) const;
};
