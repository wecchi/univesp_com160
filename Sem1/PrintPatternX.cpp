/*
    Write programs called PrintPatternX.cpp (where X from A to D) to print EACH of the following patterns. Use one "cout <<" for each line of outputs. End each line by printing an "endl".
    * * * * *      * * * * *     * * * * *         *
     * * * * *     *       *      *     *         * *
    * * * * *      *       *       *   *         *   *
     * * * * *     *       *        * *           * *
    * * * * *      * * * * *         *             *
    (a)            (b)           (c)           (d)
*/
#include <iostream>
using namespace std;

int main(){
    cout << "Pattern (a):\n" << "* * * * *\n" << " * * * * *\n" << "* * * * *\n" << " * * * * *\n" << "* * * * *\n" << endl;
    cout << "Pattern (b):\n" << "* * * * *\n" << "*       *\n" << "*       *\n" << "*       *\n" << "* * * * *\n"<< endl;
    cout << "Pattern (c):\n" << "* * * * *\n" << " *     *\n" << "  *   *\n" << "   * *\n" << "    *\n"<< endl;
    cout << "Pattern (d):\n" << "    *\n" << "  *   *\n" << "*       *\n" << "  *   *\n" << "    *\n"<< endl;
    return 0;
}