/* Videoaula 12 -  18:45
  * Implementando a classe Hash com uma estrutura linear para evitar colisão
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

 int Hash::getHash(Aluno aluno){
     return aluno.getRa() % max_items;
 }

 // Deverá examinar endereços consecutivos, iniciando em A[h(k)], até encontrar a chave igual a k.
 // Se k não existir, então a retrieveItem finalizará em uma posição vazia. 
 // O nome "Teste Linear" ocorre porque acessar A[h(k)] implica em testar a chave para verificar se encontramos a entrada desejada
 void Hash::retrieveItem(Aluno& aluno, bool& found){
     int startLoc = getHash(aluno); // tratando como uma localização inicial
     bool moreToSearch = true;      // continuar busca?
     int location = startLoc;       // buscar no vetor
     do {
         if (structure[location].getRa() == aluno.getRa() || structure[location].getRa() == -1) // encontrado ou posição vazia
            moreToSearch = false;
        else
            location = (location + 1) % max_items; // não encontrado, então vamos a próxima posição (linear)
     } while (location != startLoc && moreToSearch);
     found = (structure[location].getRa() == aluno.getRa());
     if (found)
        aluno = structure[location];
 }

void Hash::insertItem(Aluno aluno){
    int location = getHash(aluno);
    // tratamos os elementos com RA –1 e os elementos com RA –2 como possíveis para alocação.
    while (structure[location].getRa()>0)
    {
        location = (location + 1) % max_items;
    }
    // Note que não tratamos o caso em que a estrutura está cheia. Isso levaria a um looping infinito
    structure[location] = aluno;
    lenght++;
}

 // faremos uma busca semelhante ao retrieveItem antes de marcar o elemento com RA –2 (valor -2 será como "disponível")
void Hash::deleteItem(Aluno aluno){
    int startLoc = getHash(aluno); // tratando como uma localização inicial
    bool moreToSearch = true;      // continuar busca?
    int location = startLoc;       // buscar no vetor
    do {
        if (structure[location].getRa() == aluno.getRa() || structure[location].getRa() == -1) // encontrado ou posição vazia
        moreToSearch = false;
    else
        location = (location + 1) % max_items; // não encontrado, então vamos a próxima posição (linear)
    } while (location != startLoc && moreToSearch);

    if (structure[location].getRa() == aluno.getRa()){
        structure[location] = Aluno(-2, "");     // a posição a ser excluída ficará como "disponível"
        lenght--;
    }
 }

 // Impressão dos registros da tabela
void Hash::print(){
    for (int i = 0; i < max_items; i++){
        cout << i << " = " <<
            structure[i].getRa() << ":" <<
            structure[i].getNome() << endl;
    }
}

// Novo método para atualização de informação
void Hash::updateItem(Aluno& aluno, int novoRA, string novoNome){
    Aluno novoAluno = Aluno(novoRA, novoNome);
    deleteItem(aluno);
    insertItem(novoAluno);
}