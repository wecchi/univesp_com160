 /* Videoaula 4 -  19:41 
  * Implementação da classe Time
  */

#include "time.h"
#include <iostream>

using namespace std;

int main(){
    Time t1(23, 59, 59);
    t1.print();
    t1.setHour(12);
    t1.print();
    t1.setMinute(30);
    t1.print();
    t1.setSecond(15);
    t1.print();

    cout << "Hour: " << t1.getHour() << endl;
    cout << "Minute: " << t1.getMinute() << endl;
    cout << "Second: " << t1.getSecond() << endl;

    // Nesta segunda instância usamos padrão para os minutos e segundos:
    Time t2(12);
    t2.print();
    t2.setSecond(59);
    t2.nextSecond();
    t2.print();

    return 0;

}
