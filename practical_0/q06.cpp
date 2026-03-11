//================================================
// Q06: Loop-Based Pattern Generation
// For loops, nested loops, and patterns
//================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName = "Pema";
    string fullName = "Pema Tshering Yangchen";
    int studentNumber = 2230295;

    // 1. Print first name N times (where N = length of first name)
    cout << "Name repeated (" << firstName.length() << " times):" << endl;
    for (int i = 0; i < firstName.length(); i++) {
        cout << firstName << endl;
    }
    
    // 2. Print triangle of asterisks (height = length of full name)
    cout << "\nTriangle (height = " << fullName.length() << "):" << endl;
    for (int i = 1; i <= fullName.length(); i++) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    // 3. Print multiplication table for last digit of student number
    int lastDigit = studentNumber % 10;
    cout << "\nTimes Table for " << lastDigit << " (last digit of " << studentNumber << "):" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << lastDigit << " x " << i << " = " << (lastDigit * i) << endl;
    }
    
    return 0;
}