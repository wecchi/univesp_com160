/*
 * Convert temperature between Celsius and Fahrenheit
 * (ConvertTemperature.cpp)
 */
#include <iostream>
using namespace std;
 
int main() {
   double celsius, fahrenheit;
 
   cout << "Enter the temperature in celsius: ";
   cin >> celsius;
   fahrenheit = celsius * 9.0 / 5.0 + 32.0;
   cout << celsius << " degree C is " << fahrenheit << " degree F." << endl << endl;
 
   cout << "Enter the temperature in fahrenheit: ";
   cin >> fahrenheit;
   celsius =  (fahrenheit - 32.0) * 5.0 / 9.0;
   cout << fahrenheit << " degree F is " << celsius << " degree C." << endl;
 
   return 0;
}