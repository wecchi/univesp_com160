/*
 * Exercises https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp0_Introduction.html
 * Follow the above example, write a program called CylinderComputation.cpp to print the surface area and volume of a cylinder. 
 * Your program shall prompt the user for the radius and height of the cylinder, in doubles.
 */

#include <iostream>

using namespace std;

const double PI = 3.141592653589793238;

// Function to calcule surface
double surface(double &baseradius, double &height){
    return 2*(PI * baseradius * baseradius) + (2 * PI * baseradius * height);
}

// Function to calcule volume
double volume(double &baseradius, double &height){
    return PI * baseradius * baseradius * height;
}

int main(){
    double baseradius, height;
    // Prompt to imput data
    cout << "Enter for the radius and height of the cylinder (separed by space): ";
    cin >> baseradius >> height;

    // Print results
    cout << "Surface: " << surface(baseradius, height) << endl;
    cout << "Volume: " << volume(baseradius, height) << endl;
    return 0;
}