 /* Videoaula 14 -  08:52
  * Implementação da classe 'tree'
  */

 #include "tree.h"
 #include <iostream>

 using namespace std;

// O método privado _destroyTree efetua um caminhamento pós-ordem: Esquerda-Direita-Raiz
void Tree::destroyTree(NodeType *& tree){
    if (tree != NULL){
         destroyTree(tree->esquerdo);
         destroyTree(tree->direito);
         delete tree;
    }
 }

// Caso o ponteiro 'root' esteja apontando para uma região vazia, significa que a árvore está vazia:
bool Tree::isEmpty() const{
    return root == NULL;
}

// Para verificar se a árvore está cheia, tenta-se criar um novo 'NodeType', se conseguir, ainda existe memória disponível
bool Tree::isFull() const{
    NodeType *test;
    try{
        test = new NodeType;
        delete test;
        return false;
    } catch (bad_alloc exception){ // Não conseguiu alocar erro! Retorna true, a árvore está cheia
        return true;
    }
}

// Buscando um aluno na árvore binária (percurso InOrdem):
void Tree::retrieveAluno(NodeType *tree, Aluno &aluno, bool &found) const {
    if (tree == NULL)
        found = false;
    else if (aluno.getRa() < tree->aluno.getRa())
        retrieveAluno(tree->esquerdo, aluno, found);
    else if (aluno.getRa() > tree->aluno.getRa())
        retrieveAluno(tree->direito, aluno, found);
    else {
        aluno = tree->aluno;
        found = true;
    }
}

// Inserindo aluno (presumindo que não será tentado incluir um Ra que já existia):
void Tree::insertAluno(NodeType *& tree, Aluno novoaluno){
    // Árvore vazia? 1º nó será o root
    if (tree == NULL){
        tree = new NodeType;
        tree->direito = NULL;
        tree->esquerdo = NULL;
        tree->aluno = novoaluno;
    } else if (novoaluno.getRa() < tree->aluno.getRa()) // Ra do novoaluno é menor que o RA do nó atual
        insertAluno(tree->esquerdo, novoaluno);
    else
        insertAluno(tree->direito, novoaluno);          // Ra do novoaluno é maior que o RA do nó atual
}

// Imprimindo a lista na saída padrão Pré-Ordem: visiar Raiz-Esquerda-Direita
void Tree::printPreOrder(NodeType *tree) const{
    if (tree != NULL){
        cout << tree->aluno.getNome() << ", ";
        printPreOrder(tree->esquerdo);
        printPreOrder(tree->direito);
    }
}

// Imprimindo a lista na saída padrão In-Ordem: visiar Esquerda-Raiz-Direita
void Tree::printInOrder(NodeType *tree) const{
    if (tree != NULL){
        printInOrder(tree->esquerdo);
        cout << tree->aluno.getNome() << ", ";        
        printInOrder(tree->direito);
    }
}

// Imprimindo a lista na saída padrão Pós-Ordem: visiar Esquerda-Direita-Raiz
void Tree::printPosOrder(NodeType *tree) const{
    if (tree != NULL){
        printPosOrder(tree->esquerdo);
        printPosOrder(tree->direito);
        cout << tree->aluno.getNome() << ", ";          
    }
}

/* Videoaula 15 -  02:34
 * Iremos efetuar agora a remoção de um nó da árvore. O nosso código é dividido em algumas etapas:
 *      - deleteAluno: um método que navegará pela arvore até encontrar o nó a ser excluído.
 *      - deleteNode: um método que receberá por parâmetro o nó a ser excluído e tratará três casos:
 *          O nó é uma folha.
 *          O nó tem um filho.
 *          O nó tem dois filhos (busca e substituição pelo sucessor lógico).
 */
void Tree::deleteAluno(NodeType *&tree, int ra){
    if (ra < tree->aluno.getRa())       // o RA a ser excluído é menor (está a esquerda) do nó atual
        deleteAluno(tree->esquerdo, ra);
    else if (ra > tree->aluno.getRa())  // o RA a ser excluído é maior (está a direita) do nó atual
        deleteAluno(tree->direito, ra);
    else if (ra == tree->aluno.getRa()) // o RA a ser excluído é igual (é a raiz) do nó atual
        deleteNode(tree);
}

void Tree::deleteNode(NodeType *& tree){
    Aluno tempData;
    NodeType *tempPtr;
    tempPtr = tree;
    if (tree->esquerdo == NULL){ // Verificando se não existe nó maior que o atual (subárvore da esquerda)
        tree = tree->direito;   // realoca o nó atual para o da direita (único filho à direita)
        delete tempPtr;         // exclui o nó em questão
    } else if (tree->direito == NULL){  // Verificando se não existe nó menor que o atual (subárvore da direita)
        tree = tree->esquerdo;          // realoca o nó atual para o da esquerda (único filho à esquerda)
        delete tempPtr;                 // exlui o nó em questão
    } else {
        getSucessor(tree, tempData);
        tree->aluno = tempData;
        deleteAluno(tree->direito, tempData.getRa());
    }
}

/*
 * Removendo aluno: o próximo caso precisará do predecessor lógico ou do sucessor lógico. 
 * Escolhemos utilizar o sucessor lógico. O sucessor lógico é o filho mais à esquerda da árvore da direita. 
 * Procuramos esse nó e retornamos no parâmetro data, passado por referência
 */
void Tree::getSucessor(NodeType *tree, Aluno &data){
    tree = tree->direito; // O tree é o nó onde buscamos o sucessor lógico
    while (tree->esquerdo != NULL)
        tree = tree->esquerdo;
    data = tree->aluno; // retorna por referência o nó folha mais a esquerda da 1ª subárvore da direita
    
}