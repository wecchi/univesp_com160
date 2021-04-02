 /* Videoaula 16 -  13:41
  * Definição da classe abstrata para árvore AVL
  * Precisaremos armazenar o fator de balanceamento, além das outras informações que já guardávamos.
  * Note que não precisamos modificar a classe Aluno.
  */

#include "aluno.h"
#include <cstddef> // Define vários tipos gerados implicitamente ou usados ​​por certas expressões de linguagem C++

struct NodeType
{
    Aluno aluno;
    int fatorBalanceamento;
    NodeType* esquerdo;
    NodeType* direito;
};

class TreeAVL{
    // Interface pública invocando métodos recursivos privados
    public:
        TreeAVL(){root = NULL;}
        ~TreeAVL(){ destroyTree(root);}
        bool isEmpty() const;
        bool isFull() const;
        void retrieveAluno(Aluno &item, bool &found) const{
            retrieveAluno(root, item, found);
        }

        /* 
         * isTaller e isShorter servem para saber se a árvore cresceu na inserçãou ou decresceu 
         * na remoção (para gerenciar o fator de balanceamento).
         * Toda vez que um aluno for inserido, precisamos checar se a árvore cresceu ou não
         */ 
        void insertAluno(Aluno item){
          bool isTaller;
          insertAluno(root, item, isTaller);
        }
        // Toda vez que um aluno for excluído, precisamos checar se a árvode decresceu seu fator de balanceamento
        void deleteAluno(int ra){
          bool isShorter;
          deleteAluno(root, ra, isShorter);
        }

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
        void insertAluno(NodeType *&tree, Aluno item, bool &isTaller); // Ponteiro por referência
        void deleteAluno(NodeType *&tree, int ra, bool &isShorter);    // Ponteiro por referência
        void deleteNode(NodeType *&tree, bool& isShorter);
        void getSucessor(NodeType *tree, Aluno &data); // Ponteiro por referência
        void rotateToLeft(NodeType *&tree) const;
        void rotateToRight(NodeType *&tree) const;
        void rotateToLeftAndRight(NodeType *&tree) const;
        void rotateToRightAndLeft(NodeType *&tree) const;
        void performRotations(NodeType *&tree) const;
        void printTree(NodeType *tree) const;
        void printPreOrder(NodeType *tree) const;
        void printInOrder(NodeType *tree) const;
        void printPosOrder(NodeType *tree) const;
};