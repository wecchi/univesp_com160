#include <iostream>

using namespace std;

 /* Videoaula 1 -  20:38 
    Declarações de funções
 */

/* função para somar 2 números */
int sum(int number1, int number2){
    return number1 + number2;
}

/* função para subtrair 2 números */
int sub(int number1, int number2){
    return number1 - number2;
}

/* função para multiplicar 2 números */
int mul(int number1, int number2){
    return number1 * number2;
}

/* função para obter a parte inteira de uma divisão */
int idiv(int number1, int number2){
    return number1 / number2;
} 

int main() {
    int number1;
    int number2;

    cout << "Digite o primeiro numero:";
    cin >> number1;
    cout << "Digite o segundo numero:";
    cin >> number2;

    cout << "Soma: " << sum(number1, number2) << "\nSubtracao: " << sub(number1, number2) << "\nMultiplicacao: " << mul(number1, number2) << "\nInteiro da divisao: " << idiv(number1, number2) << endl;

    return 0;
}

