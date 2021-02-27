/*
 * Exercises https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp0_Introduction.html
 * Write a program called GeometricSeriesSum to compute the sum of a geometric series 1 + 1/2 + 1/4 + 1/8 + .... + 1/n. 
 * You program shall prompt for the value of n. (Hints: Use post-processing statement of denominator = denominator * 2.)
 */

#include <iostream>
using namespace std;
 
int main() {
   int maxDenominator;  // max denominator to sum to
   double sum = 0.0;    // For accumulating sum in double

   // Prompt user for the maxDenominator
   cout << "Take the value of 'n' of geometric series: ";
   cin >> maxDenominator;

   int denominator = 1;
   while (denominator <= maxDenominator) {
      // Beware that int/int gives int
      sum += 1/(double)denominator;
      denominator *=2;  // next
   }
   // Print the sum
   cout << "Result of the sum for n=" << maxDenominator << " is " << sum << endl;
   return 0;
}