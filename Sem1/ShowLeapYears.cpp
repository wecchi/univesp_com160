/*
 * Exercises https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp0_Introduction.html
 * Write a program to print all the leap years between AD1 and AD2010, and also print the number of leap years.
 * (Hints: use a variable called count, which is initialized to zero. Increment the count whenever a leap year is found.)
 */

#include <iostream>

using namespace std;

bool isLeapYear(int &year){
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 ==0));
}

int main(){

    int iniYear = 1, endYear = 2010, sum =0;
    cout << "Enter two years (separated by space): ";
    cin >> iniYear >> endYear;
    cout << "Leap years: ";

    for (int i = iniYear; i <= endYear; i++){
        if (isLeapYear(i)){
            cout << i;
            if (i < endYear) cout << ", ";
            else cout << "." << endl;
            sum++;
        }
    }

    cout << "\nThe number of leap years: " << sum << endl;

    return 0;
}