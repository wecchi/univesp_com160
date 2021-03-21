/* Videoaula 11 -  07:32
  * Implementando a classe Hash com uma estrutura básica
  * Vamos criar uma estrutura minimalista, apenas com busca, inserção e remoção
  */

 #include "hash.h"
 #include <iostream>
 
 using namespace std;

// Contrutor do tamanho da tabela (quantidade de registros)
 Hash::Hash(int max){
     lenght = 0;
     max_items = max;
     structure = new Aluno[max_items];
 }

 // Destrutor
 Hash::~Hash(){
     delete [] structure;
 }

 // Verifica a taleba está cheia
 bool Hash::isFull() const{
     return (lenght == max_items);
 }

 // Obtém o endereçamento do registro (o RA é um número inteiro, como queremos utilizar essa informação como índide do vetor, 
 // vamos usar o resto da divisão da quantidade máxima de elementos para evitar que os 1ºs locais fiquem vagos no vetor)
 // Estamos assumindo que não irá gerar colisão, isto é, não haverá restos iguais para RA's diferentes
 int Hash::getHash(Aluno aluno){
     return aluno.getRa() % max_items;
 }

 // retorna uma entrada com chave igual a k, se ela existir. Caso contrário, retorna nulo.
 // passamos por referência os parâmetos aluno e found (se localizou ou não)
void Hash::retrieveItem(Aluno& aluno, bool& found){
    int location = getHash(aluno);
    Aluno temp = structure[location];
    if (aluno.getRa() != temp.getRa()) {
        found = false;
    } else {
        found = true;
        aluno = temp;
    }
}

// Insere uma entrada v na chave k se a chave não existir. Caso contrário, atualiza o valor associado a k. 
void Hash::insertItem(Aluno aluno){
    int location = getHash(aluno);
    structure[location] = aluno;
    lenght++;
}

// Exclusão de um registro
void Hash::deleteItem(Aluno aluno){
    int location = getHash(aluno);
    structure[location] = Aluno();
    lenght--;
}

// Impressão dos registros da tabela
void Hash::print(){
    for (int i = 0; i < max_items; i++){
        cout << i << " = " <<
            structure[i].getRa() << ":" <<
            structure[i].getNome() << endl;
    }
}

// Novo método para atualização de informação - supondo que não hajam colisões
void Hash::updateItem(Aluno& aluno, int novoRA, string novoNome){
    int index = getHash(aluno);
    Aluno temp = structure[index];

    Aluno novoAluno = Aluno(novoRA, novoNome);
    int novoIndex = getHash(novoAluno);
    
    if (aluno.getRa() == temp.getRa()) { // Aluno a ser modificado foi encontrado
        structure[index] = Aluno();      // Desaloca o ponteiro para o aluno "anterior"
        structure[novoIndex] = novoAluno;
    }    
}
