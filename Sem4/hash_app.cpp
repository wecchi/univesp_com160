/* Videoaula 11 -  16:46
  * Testando a estrutura de inserção de alunoa na tabela Hash
  */

#include <iostream>
#include "hash.h"
#include <locale.h>

using namespace std;

int main(){
    // habilita a acentuação para Português - Brasil vide tabela em: https://docs.microsoft.com/pt-br/openspecs/windows_protocols/ms-lcid/a9eac961-e77d-41a6-90a5-ce1a8b0cdb9c
    setlocale(LC_ALL, "portuguese-brazilian"); //"pt_BR.utf8"); 
    //printf("A localidade corrente agora é %s \n", setlocale(LC_ALL, "")); // volta ao padrão do Sistema Operacional

    Hash alunosHash(10);
    int   ras[9]   = {12704, 31300, 1234, 49001, 52202, 65606, 91234, 5200, 8955};
    string nomes[9] = {"Pedro", "Raul", "Paulo", "Carlos", "Lucas", "Maria", "Samanta", "Amanda", "Joana"}; 
	cout << "Endereco dos RAs: " << ras << endl;
    cout << "Endereco dos Nomes: " << nomes << endl << endl;

    for (int i = 0; i < 9; i++) {
        Aluno aluno = Aluno(ras[i], nomes[i]);
        alunosHash.insertItem(aluno);
    }
    alunosHash.print();

    cout << "-------Existe o aluno de RA 12704? -----------------" <<  endl;
    Aluno aluno1(12704,"");  
    bool     found1 = false;
    alunosHash.retrieveItem(aluno1, found1);
    cout << aluno1.getNome() << " -> " << found1 << " (1-sim; 0-nao)" << endl;
        cout << "----------------------------------------------------" <<  
        endl << "\n> Excluindo o aluno de RA 12704..." << endl << endl;
    alunosHash.deleteItem(aluno1);

    cout << "-------Existe o aluno de RA 52202? -----------------" <<  endl;
    Aluno aluno2(52202,"");  
    bool     found2 = false;
    alunosHash.retrieveItem(aluno2, found2);
    cout << aluno2.getNome() << " -> " << found2 << " (1-sim; 0-nao)" << endl;
        cout << "----------------------------------------------------" <<  
        endl << "\n> Excluindo o aluno de RA 52202..." << endl << endl;
    alunosHash.deleteItem(aluno2);    

    cout << "----------- Lista atualizada dos alunos  ----------------" <<  endl;
    alunosHash.print();

    cout << endl << "-------Alteracao do RA 49001 para 1901 -----------------" <<  endl;
    Aluno aluno3(49001, "");
    alunosHash.updateItem(aluno3, 1901, "Carlos");
    cout << endl << "------- Alteracao do Nome Joana para Valeria -----------------" <<  endl;
    Aluno aluno4(8955, "");
    alunosHash.updateItem(aluno4, 8955, "Valeria");
    cout << endl << "------- Alteracao do Nome e RA da Amanda -----------------" <<  endl;
    Aluno aluno5(5200, "");
    alunosHash.updateItem(aluno5, 8880, "Ana Maria");
    cout << endl << "----------- Lista final dos alunos  ----------------" <<  endl;
    alunosHash.print();
    cout << endl << "----------------------- FIM -----------------------" << endl; 

    return 0;
}