 /* Videoaula 14 -  01:36
  * Definição da classe abstrata para aluno
  * Vamos supor  que queremos organizar alunos em uma estrutura e, posteriormente, 
  * fazer buscas pelo registro acadêmico desse aluno (ra).
  */

#include <string>
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