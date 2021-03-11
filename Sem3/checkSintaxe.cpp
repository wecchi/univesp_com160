/* Videoaula 8 -  22:00
  * Implementando a aplicação de verificar abertura e fechamento de {{()}}
  */

 #include "stack.h"
 #include <iostream>

 using namespace std;

 int main(){
     ItemType letra;
     Stack pilha;
     ItemType itemPilha;
     bool isMatched = true;

     cout << "Forneca uma estrtura literal: ";
     cin.get(letra);
     while (isMatched && letra != '\n')
     {
        if (letra == '{' || letra == '[' || letra == '('){
            pilha.push(letra); // Inclua o caracter na pilha
        }
        if (letra == '}' || letra == ']' || letra == ')'){
            if (pilha.isEmpty()){
                isMatched = false; // pilha vazia, caracter a mais de fechamento
            } else {
                itemPilha = pilha.pop();
                isMatched = (
                    (letra == '}' && itemPilha == '{')   // Chaves estão pareadas?
                    ||(letra == ']' && itemPilha == '[') // Colchetes estão pareados?
                    ||(letra == ')' && itemPilha == '(') // Parênteses estão pareados?
                );
            }
        }
        cin.get(letra);
     }
     
     if (isMatched && pilha.isEmpty()){
         cout << "BEM FORMADA\n";
     } else {
         cout << "MAL FORMADA!\n";
         pilha.print();
     }
     return 0;
 }