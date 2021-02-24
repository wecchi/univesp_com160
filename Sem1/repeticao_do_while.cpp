#include <iostream>

using namespace std;

 /* Videoaula 1 -  19:00 
    Comandos de repetição - "do-while" (faça até que - teste na saída do laço)
 */

int main() {
    int count;
    int number;
    int sum;

    do {
        cout << "Insira um numero (ou 0 para finalizar): " << endl;
        cin >> number;

        sum += number;
        count++;
    } while (number != 0);

    float average = (float)sum/(float)count;
    cout << "A media da serie e: " << average << endl;

    return 0;
}