#include <iostream>

using namespace std;

 /* Videoaula 1 -  14:34 
    Comandos de repetição - "While" (enquanto - teste no início do laço)
 */

int main()
{
    int number1;
    int counter = 0;
    int amount = 0;

    while (counter < 10) {
        cout << "Digite o numero " << counter + 1 << ":";
        cin >> number1;

        if (number1 < 5){
            amount++;
        }

        counter++;
    }

    cout << "foram digitados " << amount << " numeros menores que 5" << endl;

    return 0;
}