#include "treeavl.h"
#include <iostream>

using namespace std;

const int NUM_ALUNOS = 15;

void printAll(TreeAVL &arvoreAlunos){
    // Imprimindo na saída padrão:
    cout << "Pre:\t";
    arvoreAlunos.printPreOrder();
    cout << "\nIn:\t";
    arvoreAlunos.printInOrder();
    cout << "\nPos:\t";
    arvoreAlunos.printPosOrder();
    cout << endl;    
}

int main(){
    TreeAVL arvoreAlunos;
    const int ras[NUM_ALUNOS] = {19, 20, 22, 18, 58, 7, 19, 26, 30, 25, 2, 5, 60, 35, 45};
    const string nomes[NUM_ALUNOS] = {
        "Pedro", "Raul", "Paulo", "Carlos", "Lucas", "Enelton", 
        "Cristhof", "Danielle", "Meira", "Guilherme", "Juliana", 
        "Maria", "Ulisses", "Samanta", "Gabriela"};
    //Aluno alunos[NUM_ALUNOS];

    for (int i = 0; i < NUM_ALUNOS; i++){
        Aluno aluno = Aluno(ras[i], nomes[i]);
        //alunos[i] = aluno;
        arvoreAlunos.insertAluno(aluno);
    }

    printAll(arvoreAlunos);

    // Removendo o aluno da raiz da árvore:
    arvoreAlunos.deleteAluno(ras[0]);
    cout << "\n------- >> Removendo o aluno da raiz << -------\n";
    printAll(arvoreAlunos);

    // Removendo alguns alunos
    cout << "\n------- >> Removendo mais alguns alunos << -------\n";
    cout << nomes[11] << ", " << nomes[5] << ", " << nomes[9] << endl;
    arvoreAlunos.deleteAluno(ras[11]);
    arvoreAlunos.deleteAluno(ras[5]);
    arvoreAlunos.deleteAluno(ras[9]);
    printAll(arvoreAlunos);

    return 0;
}