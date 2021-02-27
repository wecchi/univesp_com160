/*
 * Exercises https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp0_Introduction.html
 * Write a program to sum all the integers between 1 and 1000, that are divisible by 13, 15 or 17, but not by 30.
 */

#include <iostream>

using namespace std;

bool isDivisible(int &number, int by){
    return number % by == 0;
}

int main(){

    int sum;

    for (int i = 1; i <= 1000; i++){
        if ((isDivisible(i, 13) || isDivisible(i, 15) || isDivisible(i, 17)) && !isDivisible(i, 30)){
            sum = sum + i;
        }
    }

    cout << "The sum all the integers between 1 and 1000, that are divisible by 13, 15 or 17, but not by 30 is: " << sum << endl;

    return 0;
}