/* Videoaula 15 -  14:49
 * Aplicação de inserção de uma lista de alunos
 */

#include "tree.h"
#include <iostream>

using namespace std;

const int NUM_ALUNOS = 8;

int main(){
    Tree arvoreAlunos;
    int ras[NUM_ALUNOS] = {20, 18, 58, 7, 19, 26, 30, 25};
    string nomes[NUM_ALUNOS] = {"Pedro", "Raul", "Paulo", "Carlos", "Lucas", "Maria", "Ulisses", "Samanta"};
    Aluno alunos[NUM_ALUNOS];

    for (int i = 0; i < NUM_ALUNOS; i++){
        Aluno aluno = Aluno(ras[i], nomes[i]);
        alunos[i] = aluno;
        arvoreAlunos.insertAluno(aluno);
    }

    // Imprimindo na saída padrão:
    cout << "Pre:\t";
    arvoreAlunos.printPreOrder();
    cout << "\nIn:\t";
    arvoreAlunos.printInOrder();
    cout << "\nPos:\t";
    arvoreAlunos.printPosOrder();
    cout << endl;

    // Removendo o aluno da raiz da árvore:
    arvoreAlunos.deleteAluno(alunos[0].getRa());
    cout << "\n------- >> Removendo o aluno da raiz << -------\n" << "Pre:\t";
    arvoreAlunos.printPreOrder();
    cout << "\nIn:\t";
    arvoreAlunos.printInOrder();
    cout << "\nPos:\t";
    arvoreAlunos.printPosOrder();
    cout << endl;
    return 0;
}