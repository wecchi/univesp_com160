#include <iostream>

using namespace std;

 /* Videoaula 3 -  13:42 
    Verificando três diferentes formas de tratar a ponteiros por um método
 */

// Neste método a variável "p" será local e não irá alterar o valor original
void by_val_new_mem(int* p)
{
    // nova referência para p (local)
    p = new int;
    *p = 7;
}

// Alterando o valor na memória
void by_val_modif_mem(int* p)
{
    *p = 8;
}

// Neste método a variável "p" ganha nova referência e novo valor
void by_ref_modif_all(int*& p)
{
    // nova referência
    p = new int;
    // novo valor
    *p = 9;
}

int main()
{
    int a = 1, b = 2, c = 3;
    int* p1 = &a;
    int* p2 = &b;
    int* p3 = &c;

    // Imprimindo a sequencia dos métodos aplicados:
    cout << "\nby_val_new_mem\tby_val_modif_mem\tby_ref_modif_all\n";

    // Imprimindo os ponteiros e seus valores
    cout << "Before:\n \t" << p1 << "\t" << p2 << "\t" << p3 << endl;
    cout << "\t\t" << *p1 << "\t\t" << *p2 << "\t\t" <<* p3 << endl;

    //chamando ps métodos
    by_val_new_mem(p1);
    by_val_modif_mem(p2);
    by_ref_modif_all(p3);

      // Imprimindo os ponteiros e seus valores
    cout << "\nAfter:\n \t" << p1 << "\t" << p2 << "\t" << p3 << endl;
    cout << "\t\t" << *p1 << "\t\t" << *p2 << "\t\t" <<* p3 << endl;
    cout << "\nVariables:\ta\t\tb\t\tc\n \t" << &a << "\t" << &b << "\t" << &c << endl;
    cout << "\t\t" << a << "\t\t" << b << "\t\t" << c << endl;

    return 0;
}