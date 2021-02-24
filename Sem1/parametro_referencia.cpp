#include <iostream>

using namespace std;

 /* Videoaula 1 -  23:57 
    Exemplo de passagem de parâmetro para uma função "por referência" (ver & antes do nome do parâmetro)
 */

void troca_por_referencia(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    int a=2, b=3;
    cout << "Antes: a = " << a << ", b = " << b << endl;
    troca_por_referencia(a, b);
    cout << "Depois: a = " << a << ", b = " << b << endl;

    return 0;
}