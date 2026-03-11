//================================================
// Q04: User Input & Type Conversion
// Handling user input and basic calculations
//================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int studentNumber;
    int age;
    
    // Get user input
    cout << "Enter your name : ";
    getline(cin, name);  // Use getline for names with spaces
    
    cout << "Enter student number : ";
    cin >> studentNumber;
    
    cout << "Enter your age : ";
    cin >> age;
    
    // Calculate birth year and year when they turn 100
    int currentYear = 2026;
    int birthYear = currentYear - age;
    int year100 = birthYear + 100;
    
    // Display formatted summary
    cout << "----------------------------------------" << endl;
    cout << "Summary" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Name : " << name << endl;
    cout << "Student No : " << studentNumber << endl;
    cout << "Year of Birth : " << birthYear << endl;
    cout << "Year at Age 100: " << year100 << endl;
    
    return 0;
}