/* Videoaula 11 -  01:07
  * Criando a classe abstrata Aluno
  * Vamos supor que queremos organizar alunos em uma estrutura e, posteriormente, fazer buscas pelo registro acadêmico (ra).
  */
#include <iostream>
using namespace std;

 class Aluno{
     private:
        int ra;
        string nome;

    public:
        Aluno();
        Aluno(int ra, string nome);
        string getNome() const;
        int getRa() const;

 };