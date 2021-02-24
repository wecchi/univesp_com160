#include <iostream>

using namespace std;

 /* Videoaula 1 -  16:39 
    Operações matemáticas básicas
 */

int main()
{
int number1;
int number2;

cout << "Digite o primeiro numero:";
cin >> number1;
cout << "Digite o segundo numero:";
cin >> number2;

int sum = number1 + number2;
int sub = number1 - number2;
int mul = number1 * number2;
int div = number1 / number2;
float fdiv = (float)number1 / float(number2);
int res = number1 % number2;

cout << "Soma: " << sum << "\nSubtracao: " << sub << "\nMultiplicacao: " << mul << "\nDivisao: " << div << "\nFloat: " << fdiv << "\nResto: " << res;

return 0;
}