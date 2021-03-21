/* Videoaula 11 -  05:56
  * Criando a classe abstrata Hash
  * Vamos criar uma estrutura minimalista, apenas com busca, inserção e remoção
  */

 #include "aluno.h"
using namespace std;

 class Hash{
    public:
        Hash(int max_items = 100);  // Construtor
        ~Hash();
        bool isFull() const;
        int getLength() const;

        void retrieveItem(Aluno& aluno, bool& found);
        void insertItem(Aluno aluno);
        void deleteItem(Aluno aluno);
        void updateItem(Aluno& aluno, int novoRA, string novoNome);
        void print();

    private:
        int getHash(Aluno aluno);
        int max_items;      // Quantidade máxima de alunos para o vetor dinâmico (se nada for informado, será = 100)
        int lenght;         // Quantidade real de alunos
        Aluno* structure;   // Vetor de objetos aluno
 };