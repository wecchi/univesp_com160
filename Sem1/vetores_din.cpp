#include <iostream>

using namespace std;

 /* Videoaula 3 -  10:00 
    Declaração e inicialização de vetores dinâmicos
 */

int main()
{
    int num_elem;
    cout << "Informe o tamanho do vetor: " << endl;
    cin >> num_elem;

    // Declarando e inicializando os elementos do vetor dinâmico:
    int* c = new int[num_elem];
    for (int i = 0; i < num_elem; i++){
        c[i] = 2*i;
    }

    // Imprimindo os valores na tela
    for (int i = 0; i < num_elem; i++){
        cout << "c[" << i << "] = " << c[i] << endl;
    }

    // Desalocando o vetor da memória
    delete [] c;

    return 0;
}