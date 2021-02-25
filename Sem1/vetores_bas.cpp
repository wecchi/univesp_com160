#include <iostream>

using namespace std;

 /* Videoaula 3 -  02:05 
    Declaração e inicialização de vetores
 */

int main()
{
    // Na declaração, informamos o tipo e o número de elementos do vetor:
    int c[10];
    // Atribuindo valor aos elementos do vetor (indexação começa por 0):
    c[5] = 30;
    c[7] = 40;
    c[8] = 50;

    // Ou podemos iterarmos com um laço:
    for (int i = 0; i < 10; i++){
        c[i] = 10 * (i + 1);
    }
    // Também podemos declarar e inicializar o vetor na mesma instrução:
    int v[5] = {14, 0, 13};

    // Ou ainda podemos declarar implicitamente o tamanho do vetor ao inicializa-lo:
    float f[] = {22.5, 0, 69.1, 53.2};

    // Recupeando os valores do vetor (acessando os elementos uma a um v[i]):
    for (int i = 0; i < 5 ; i++){
        cout << "v[" << i << "] = " << v[i] << "\n";
    }

    return 0;
}