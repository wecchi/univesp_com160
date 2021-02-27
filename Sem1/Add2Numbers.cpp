/*
 * Prompt user for two integers and print their sum, difference, product and quotient
 * (Add2Numbers.cpp)
 */
#include <iostream>
using namespace std;
 
int main() {
   int firstInt;                                           // Declare a variable named firstInt of the type int (integer)
   int secondInt;                                          // Declare a variable named secondInt of the type int
   int sum, difference, product, quotient;                 // Declare 4 variables of the type int to keep the results
 
   cout << "Enter two integers (separated by space): ";   // Display a prompting message
   cin >> firstInt >> secondInt;                          // Read two values into respective variables
 
   // Perform arithmetic operations
   sum        = firstInt + secondInt;
   difference = firstInt - secondInt;
   product    = firstInt * secondInt;
   quotient   = firstInt / secondInt;
 
   // Print the results
   cout << "The sum is: " << sum << endl;
   cout << "The difference is: " << difference << endl;
   cout << "The product is: " << product << endl;
   cout << "The quotient is: " << quotient << endl;
 
   return 0;
}