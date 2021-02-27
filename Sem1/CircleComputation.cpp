/*
 * Prompt user for the radius of a circle and compute its area and circumference
 * (CircleComputation.cpp)
 */
#include <iostream>
using namespace std;
 
int main() {
   double radius, circumference, area; // Declare 3 floating-point variables
   const double PI = 3.14159265;       // Declare and define PI
 
   cout << "Enter the radius: ";  // Prompting message
   cin >> radius;                 // Read input into variable radius
 
   // Compute area and circumference
   area = radius * radius * PI;
   circumference = 2.0 * radius * PI;
 
   // Print the results
   cout << "The radius is: " << radius << endl;
   cout << "The area is: " << area << endl;
   cout << "The circumference is: " << circumference << endl;
 
   return 0;
}