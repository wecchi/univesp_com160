/*
 * Exercises https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp0_Introduction.html
 * Follow the above example, write a program called FiveIntegerArithmetic.cpp to prompt user for 5 integers, 
 * with 5 "cin >>" statements, and print their sum and product.
 * Use five int variables integer1 to integer5 to store the five integers.
 */

#include <iostream>

using namespace std;

int main(){

    int integer1, integer2, integer3, integer4, integer5;               // Declare five pointer by int

    cout << "Enter five integers (separated by space): ";               // Display a prompting message
    cin >> integer1 >> integer2 >> integer3 >> integer4 >> integer5;    // Read two values into respective variables

    // Perform arithmetic operations
    int sum = integer1 + integer2 + integer3 + integer4 + integer5; 
    int tim = integer1 * integer2 * integer3 * integer4 * integer5;

    cout << "The sum is: " << sum << endl;
    cout << "The product is: " << tim << endl;

    return 0;
}