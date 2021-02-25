#include <iostream>

using namespace std;

 /* Videoaula 3 -  21:56 
    Quando trabalhamos com vetores, os valores serão alterados nos métodos, caso não seja tomada as devidas precauções
 */

const int N_ELEM = 10;

// Parâmetro a ser recebido é o vetor
void modif_vetor_1(int b[], int n_elem)
{
    for (int i = 0; i < n_elem; i++){
        b[i] = b[i] * 2;
    }
}

// Parâmetro a ser recebido é o ponteiro do vetor
void modif_vetor_2(int* b, int n_elem)
{
    for (int i = 0; i < n_elem; i++){
        b[i] *=3;
    }
}

// Parâmetro a ser recebido pode ser alterado para ser uma constante (imutável) e por tanto não será alterável:
void modif_vetor_3(const int* b, int n_elem)
{
    // Neste caso crio uma nova variável do mesmo tipo que será local
    int* l = new int[n_elem];
    int sum = 0;
    for (int i = 0; i < n_elem; i++){
        l[i] = 4 * b[i];
        sum += l[i];
    }
    cout << "> Soma dos elementos do vetor: [" << l << "] = " << sum << endl;
}

int main()
{
    // Alocação estática:
    int c[N_ELEM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Alocação dinâmica:
    int* d = new int[N_ELEM];
    for (int i = 0; i < N_ELEM; i++){
        d[i] = (i + 1) * 3;
    }

    // Imprimindo a sequencia dos métodos aplicados:
    cout << "\n\t\tc\t\td\n";

    // Imprimindo os ponteiros e os seus valores (cada elemento do vetor)
    cout << "Before:\n \t" << c << "\t" << d << endl;
    for (int i = 0; i < N_ELEM; i++){
        cout << "\t\t" << c[i] << "\t\t" << d[i] << endl; 
    }
     
    // Aplicando as mudanças 1:
    modif_vetor_1(c, N_ELEM);
    modif_vetor_1(d, N_ELEM);  

    // Imprimindo os ponteiros e os seus valores (cada elemento do vetor para a mudança 1)
    cout << "After (modif_vetor_1):\n \t" << c << "\t" << d << endl;
    for (int i = 0; i < N_ELEM; i++){
        cout << "\t\t" << c[i] << "\t\t" << d[i] << endl;    
    }

   // Aplicando as mudanças 2:
    modif_vetor_2(c, N_ELEM);
    modif_vetor_2(d, N_ELEM);

    // Imprimindo os ponteiros e os seus valores (cada elemento do vetor para a mudança 2)
    cout << "After (modif_vetor_2):\n \t" << c << "\t" << d << endl;
    for (int i = 0; i < N_ELEM; i++){
        cout << "\t\t" << c[i] << "\t\t" << d[i] << endl;    
    }

    // Aplicando as mudanças 3 (provar imutabilidade):
    cout << "\n Manipulacao de dados sem afetar os valores originais do vetor (imutabilidade)\n";
    modif_vetor_3(c, N_ELEM);
    modif_vetor_3(d, N_ELEM);
    cout << "\n";

    // Imprimindo os ponteiros e os seus valores (cada elemento do vetor para a mudança 2)
    cout << "After (modif_vetor_3):\n \t" << c << "\t" << d << endl;
    for (int i = 0; i < N_ELEM; i++){
        cout << "\t\t" << c[i] << "\t\t" << d[i] << endl;    
    }

    return 0;
}