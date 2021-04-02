 /* Videoaula 14 -  02:28
  * Implementação da classe 'aluno'
  */

#include "aluno.h"

using namespace std;

Aluno::Aluno(){
    this->ra = -1;
    this->nome = "";
}

Aluno::Aluno(int ra, string nome){
    this->ra = ra;
    this->nome = nome;
}

string Aluno::getNome() const{
    return nome;
}

int Aluno::getRa() const{
    return ra;
}