#include <iostream>

using namespace std;

 /* Videoaula 1 -  14:34 
    Comandos de repetição - "for" (faça "n" vezes a iteração num incremento "p")
 */

int main() {
    int total;

    for (int number =2; number <= 20; number +=2)
        total += number;

    cout << "A soma da serie e: " << total << endl;

    return 0;
}