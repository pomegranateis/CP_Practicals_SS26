//================================================
// Q02: Arithmetic with Student Number
// Mathematical operations and loops
//================================================

#include <iostream>
using namespace std;

int main() {
    int studentNumber = 2230295;
    
    int temp = studentNumber;
    int digitSum = 0;
    while (temp > 0) {
        digitSum += temp % 10;
        temp /= 10;
    }
    
    string oddEven = (studentNumber % 2 == 0) ? "Even" : "Odd";
    
    int remainder = studentNumber % 7;
    
    long long multiplied = (long long)studentNumber * 3;
    
    cout << "Student Number : " << studentNumber << endl;
    cout << "Digit Sum : " << digitSum << endl;
    cout << "Odd / Even : " << oddEven << endl;
    cout << "Remainder (% 7) : " << remainder << endl;
    cout << "Multiplied by 3 : " << multiplied << endl;
    
    return 0;
}
