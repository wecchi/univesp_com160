#include <iostream>

using namespace std;

 /* Videoaula 1 -  13:22 
    Estrutura condicional
 */

int main()
{
    int number1;
    int number2;

    cout << "Digite o primeiro numero:";
    cin >> number1;
    cout << "Digite o segundo numero:";
    cin >> number2;

    if (number1 == number2)
        cout << number1 << "==" << number2 << endl;

    if (number1 != number2)
        cout << number1 << "!=" << number2 << endl;

    if (number1 < number2)
        cout << number1 << "<" << number2 << endl;
        
    if (number1 > number2)
        cout << number1 << ">" << number2 << endl;

    return 0;
}