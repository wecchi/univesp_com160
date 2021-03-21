/* Videoaula 11 -  02:33
 * Implementaçãp da classe Aluno
 */

#include "aluno.h"

// Construtor vazio da classe (posição -1 é vazio)
Aluno::Aluno(){
    this->ra = -1;
    this->nome = "";
}

// Construtor com valores de parâmetros para a classe
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