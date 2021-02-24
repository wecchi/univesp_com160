#include <iostream>
#include <cstddef>

using namespace std;

 /* Videoaula 2 -  06:54 
    Declaração e inicialização de ponteiro para endereço de memória
    Stack nunca ficará fragmentada, enquanto a memória de Heap pode ficar fragmentada à medida que os blocos de memória são primeiro alocados e depois liberados. 
    Stack acessa variáveis ​​locais apenas enquanto Heap permite que você acesse variáveis ​​globalmente.
 */

int main()
{
    // Declarando variáveis
    int alpha, anotherInt;
    int *intPointerEstatic;
    int *intPointerDinamic;
    

    // STACK: Inicializando o ponteiro de maneira estática (operador "&" retorna o endereço da memória)
    alpha = 20;
    intPointerEstatic = &alpha;
    cout << ">STACK\nValor de alpha=" << alpha << ", localizado em " << intPointerEstatic << endl;

    // HEAP: Inicializando o ponteiro de maneira dinâmica: new aloca, delete desaloca
    intPointerDinamic = new int;
    *intPointerDinamic = 25; // alterando o valor do inteiro

    // Obtendo a região de memória onde está o valor 25:
    anotherInt = *intPointerDinamic;
    cout << ">HEAP\nValor de anotherInt=*intPointerDinamic=" << anotherInt << ", localizado em " << intPointerDinamic << endl;

    // Declarando ponteiros e apontando para vazio:
    cout << "\nDeclarando ponteiros e apontando para vazio\n";
    bool *truth = NULL;
    float *money = NULL;
    /* Trecho comentado, se for testar descomente
    // Incializando as variáveis - Se não inicializar o programa para a execução pois não existe a variável
    truth = new bool;
    money = new float;
    cout << "Valor de truth=" << *truth << ", alocado em " << truth << endl;
    cout << "Valor de money=" << *money << ", alocado em " << money << endl;
    */

    // Declarando e inicializando simultaneamente os ponteiros HEAP 
    cout << "\nDeclarando e inicializando simultaneamente os ponteiros HEAP\n";
    bool* truth2 = new bool;
    *truth2 = true;
    cout << "valor de truth2=" << *truth2 << ", alocado em " << truth2 << endl;
    float* money2 = new float;
    *money2 = 33.46;
    cout << "valor de money2=" << *money2 << ", alocado em " << money2 << endl;
    float* money3 = new float;
    cout << "valor de money3=" << *money3 << ", alocado em " << money3 << endl;

    //As duas operações a seguir são completamente diferentes
    cout << "\nAs duas operacoes a seguir sao completamente diferentes\n";
    float* mymoney = new float;
    *mymoney = *money2;
    cout << "*mymoney = *money2: valor de mymoney=" << *mymoney << ", alocado em " << mymoney << endl;
    delete mymoney;
    mymoney = money2;
    cout << "mymoney = money2: valor de mymoney=" << *mymoney << ", alocado em " << mymoney << endl;

    return 0;
}