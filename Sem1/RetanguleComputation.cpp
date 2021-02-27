/*
 * Exercises https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp0_Introduction.html
 * Follow the above example, write a program called RetanguleComputation.cpp to print the area and perimeter of a rectangle. 
 * Your program shall prompt the user for the length and width of the rectangle, in doubles.
 */

#include <iostream>

using namespace std;

// Function to calcule area
double area(double &length, double &width){
    return length * width;
}

// Function to calcule perimeter
double perimeter(double &length, double &width){
    return 2 * length + 2 * width;
}

int main(){
    double retlength, retwidth;
    // Prompt to imput data
    cout << "Enter for the length and width of the rectangle (separed by space): ";
    cin >> retlength >> retwidth;

    // Print results
    cout << "Area:      " << area(retlength, retwidth) << endl;
    cout << "Perimeter: " << perimeter(retlength, retwidth) << endl;
    return 0;
}