#include <iostream>

using namespace std;

 /* Videoaula 3 -  08:40 
    Declaração e inicialização de vetores com uma constante NUM_ELEM
    Confere mais clareza ao códico e o torna escalonável
 */
const int NUM_ELEM = 10;

int main()
{
    // Declarando e inicializando os elementos do vetor:
    int c[NUM_ELEM];
    for (int i = 0; i < NUM_ELEM; i++){
        c[i] = 2*i;
    }

    // Imprimindo os valores na tela
    for (int i = 0; i < NUM_ELEM; i++){
        cout << "c[" << i << "] = " << c[i] << endl;
    }

    return 0;
}