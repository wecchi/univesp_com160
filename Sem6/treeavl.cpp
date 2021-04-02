 /* Videoaula 16 -  15:40
  * Implementação da classe 'treeavl'
  */

 #include "treeavl.h"
 #include <iostream>

 using namespace std;

// O método privado _destroyTree efetua um caminhamento pós-ordem: Esquerda-Direita-Raiz
void TreeAVL::destroyTree(NodeType *& tree){
    if (tree != NULL){
         destroyTree(tree->esquerdo);
         destroyTree(tree->direito);
         delete tree;
    }
 }

// Caso o ponteiro 'root' esteja apontando para uma região vazia, significa que a árvore está vazia:
bool TreeAVL::isEmpty() const{
    return root == NULL;
}

// Para verificar se a árvore está cheia, tenta-se criar um novo 'NodeType', se conseguir, ainda existe memória disponível
bool TreeAVL::isFull() const{
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
void TreeAVL::retrieveAluno(NodeType *tree, Aluno &aluno, bool &found) const {
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
void TreeAVL::insertAluno(NodeType *&tree, Aluno novoaluno, bool &isTaller){
    // Ao inserir uma folha, o fator de balanceamento é zero. 
    // Além disso, avisamos o nó pai sobre o aumento de tamanho: isTaller = true
    if (tree == NULL){
        tree = new NodeType;
        tree->direito = NULL;
        tree->esquerdo = NULL;
        tree->aluno = novoaluno;
        tree->fatorBalanceamento = 0;   //Acabamos de inserir uma folha
        isTaller = true;
        return;
    } else if (novoaluno.getRa() < tree->aluno.getRa()) {// Ra do novoaluno é menor que o RA do nó atual
        insertAluno(tree->esquerdo, novoaluno, isTaller);
        if (isTaller)
            tree->fatorBalanceamento--;
    } else {
        insertAluno(tree->direito, novoaluno, isTaller);          // Ra do novoaluno é maior que o RA do nó atual
        if (isTaller)
            tree->fatorBalanceamento++;
    }

    // O performRotations vai ajustar o fatorBalanceamento
    performRotations(tree);
    // Após a rotação, a árvore não muda de tamanho
    if (isTaller && tree->fatorBalanceamento == 0){
        isTaller = false;
    }
}

// As rotações são uma implementação direta dos conceitos
// raiz +2 e filho de mesmo sinal: girar sentido anti-horário (à esquerda)
void TreeAVL::rotateToLeft(NodeType *&tree) const {
    NodeType *p = tree->direito;
    tree->direito = p->esquerdo;
    p->esquerdo = tree;
    tree = p;
}
// raiz -2 e filho de mesmo sinal: girar sentido horário (à direita)
void TreeAVL::rotateToRight(NodeType *&tree) const {
    NodeType *p = tree->esquerdo;
    tree->esquerdo = p->direito;
    p->direito = tree;
    tree = p;
}
// raiz +2 e filho de sinal oposto: girar o filho no sentido horário (à direita) e pai no sentido anti-horário (à esquerda)
void TreeAVL::rotateToLeftAndRight(NodeType *&tree) const {
    NodeType *child = tree->esquerdo;
    rotateToLeft(child);
    tree->esquerdo = child;
    rotateToRight(tree);
}// raiz +2 e filho de sinal oposto: girar o filho no sentido anti-horário (à esquerda) e pai no sentido horário (à direita)
void TreeAVL::rotateToRightAndLeft(NodeType *&tree) const {
    NodeType *child = tree->direito;
    rotateToRight(child);
    tree->direito = child;
    rotateToLeft(tree);
}

// Implementando a tabela de casos para os balanceamentos conforme fator de balanceamento
void TreeAVL::performRotations(NodeType *&tree) const {
    NodeType *child, *grandChild;
    
    if (tree->fatorBalanceamento == 2){             // Nó desbalanceado +2 (pai à esquerda)
        child = tree->direito;
        switch (child->fatorBalanceamento) {
        case 1:     //Simples à Esquerda
           tree->fatorBalanceamento = 0;
           child->fatorBalanceamento = 0;
           rotateToLeft(tree);
           break;
        case 0:     //Simples à Esquerda
            tree->fatorBalanceamento = + 1;
            child->fatorBalanceamento = - 1;
            rotateToLeft(tree);
            break;
        case -1:     //Dupla com filho para a Direita e pai para Esquerda
            grandChild = child->esquerdo;

            switch (grandChild->fatorBalanceamento){
            case -1:
                tree->fatorBalanceamento = 0;
                child->fatorBalanceamento = 1;
                break;
            case 0:
                tree->fatorBalanceamento = 0;
                tree->fatorBalanceamento = 0;
                break;
            case 1:
                tree->fatorBalanceamento = -1;
                child->fatorBalanceamento = 0;
                break;
            }
            grandChild->fatorBalanceamento = 0; 
            rotateToRightAndLeft(tree);
        }
    } else if (tree->fatorBalanceamento == -2){     // Nó desbalanceado -2 (pai à direita)
        child = tree->esquerdo;

        switch (child->fatorBalanceamento) {
        case -1 : // Simples à Direita: Caso 1
            tree->fatorBalanceamento = 0;
            child ->fatorBalanceamento = 0;
            rotateToRight(tree);
            break;      
        case 0 : // Simples à Direita: Caso 2 -> Remoções
            tree->fatorBalanceamento = -1;
            child ->fatorBalanceamento = +1;
            rotateToRight(tree);
            break;      
        case 1 :  // Rotacao dupla com Filho para a Esquerda e pai para Direita
            grandChild = child->direito;

            switch(grandChild->fatorBalanceamento){
            case -1 :
                tree ->fatorBalanceamento = +1;
                child->fatorBalanceamento =  0;      
                break;
            case 0 :
                tree ->fatorBalanceamento = 0;
                child->fatorBalanceamento = 0;
                break;
            case +1 :
                tree ->fatorBalanceamento =  0;
                child->fatorBalanceamento = -1;
                break;
            }
            grandChild->fatorBalanceamento = 0; 
            rotateToLeftAndRight(tree);
        }  
    }
}


// Imprimindo a lista na saída padrão Pré-Ordem: visiar Raiz-Esquerda-Direita
void TreeAVL::printPreOrder(NodeType *tree) const{
    if (tree != NULL){
        cout << tree->aluno.getNome() << ", ";
        printPreOrder(tree->esquerdo);
        printPreOrder(tree->direito);
    }
}

// Imprimindo a lista na saída padrão In-Ordem: visiar Esquerda-Raiz-Direita
void TreeAVL::printInOrder(NodeType *tree) const{
    if (tree != NULL){
        printInOrder(tree->esquerdo);
        cout << tree->aluno.getNome() << ", ";        
        printInOrder(tree->direito);
    }
}

// Imprimindo a lista na saída padrão Pós-Ordem: visiar Esquerda-Direita-Raiz
void TreeAVL::printPosOrder(NodeType *tree) const{
    if (tree != NULL){
        printPosOrder(tree->esquerdo);
        printPosOrder(tree->direito);
        cout << tree->aluno.getNome() << ", ";          
    }
}


void TreeAVL::deleteAluno(NodeType *&tree, int ra, bool& isShorter){
    if (ra < tree->aluno.getRa())       // o RA a ser excluído é menor (está a esquerda) do nó atual
        deleteAluno(tree->esquerdo, ra, isShorter);
        if (isShorter)
            tree->fatorBalanceamento++;
    else if (ra > tree->aluno.getRa())  // o RA a ser excluído é maior (está a direita) do nó atual
        deleteAluno(tree->direito, ra, isShorter);
        if (isShorter)
            tree->fatorBalanceamento--;
    else if (ra == tree->aluno.getRa()) // o RA a ser excluído é igual (é a raiz) do nó atual
        deleteNode(tree, isShorter);
    if (tree != NULL) {
        performRotations(tree);  
    if (isShorter && tree->fatorBalanceamento != 0){
        isShorter = false;
    }
  }
}

void TreeAVL::deleteNode(NodeType *& tree, bool& isShorter){
    Aluno tempData;
    NodeType *tempPtr;
    tempPtr = tree;
    if (tree->esquerdo == NULL){ // Verificando se não existe nó maior que o atual (subárvore da esquerda)
        tree = tree->direito;   // realoca o nó atual para o da direita (único filho à direita)
        isShorter = true;
        delete tempPtr;         // exclui o nó em questão
    } else if (tree->direito == NULL){  // Verificando se não existe nó menor que o atual (subárvore da direita)
        tree = tree->esquerdo;          // realoca o nó atual para o da esquerda (único filho à esquerda)
        isShorter = true;
        delete tempPtr;                 // exlui o nó em questão
    } else {
        getSucessor(tree, tempData);
        tree->aluno = tempData;
        deleteAluno(tree->direito, tempData.getRa(), isShorter);
        if (isShorter)
            tree->fatorBalanceamento--;
    }
}

/*
 * Removendo aluno: o próximo caso precisará do predecessor lógico ou do sucessor lógico. 
 * Escolhemos utilizar o sucessor lógico. O sucessor lógico é o filho mais à esquerda da árvore da direita. 
 * Procuramos esse nó e retornamos no parâmetro data, passado por referência
 */
void TreeAVL::getSucessor(NodeType *tree, Aluno &data){
    tree = tree->direito; // O tree é o nó onde buscamos o sucessor lógico
    while (tree->esquerdo != NULL)
        tree = tree->esquerdo;
    data = tree->aluno; // retorna por referência o nó folha mais a esquerda da 1ª subárvore da direita
    
}