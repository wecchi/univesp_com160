#include <iostream>

using namespace std;

 /* Videoaula 1 -  22:33 
    Exemplo de passagem de parâmetro para uma função "por valor"
 */

void troca_por_valor(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    int a=2, b=3;
    cout << "Antes: a = " << a << ", b = " << b << endl;
    troca_por_valor(a, b);
    cout << "Depois: a = " << a << ", b = " << b << endl;

    return 0;
}