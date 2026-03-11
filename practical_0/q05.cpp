//================================================
// Q05: Conditional Grade Classification
// If-else statements and input validation
//================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
    string studentName = "Pema Tshering Yangchen";
    int studentNumber = 2230295;
    int mark;
    
    // Get mark from user
    cout << "Enter mark: ";
    cin >> mark;
    
    // Input validation
    if (mark < 0 || mark > 100) {
        cout << "Error: Mark must be between 0 and 100!" << endl;
        return 1; // Exit with error code
    }
    
    // Classify grade using if-else if-else
    string grade, result;
    string firstName = studentName.substr(0, studentName.find(' '));
    
    if (mark >= 75) {
        grade = "Distinction";
        result = "Outstanding work, " + firstName + "! Excellent achievement.";
    } 
    else if (mark >= 60) {
        grade = "Merit";
        result = "Congratulations, " + firstName + "! You have passed.";
    } 
    else if (mark >= 40) {
        grade = "Pass";
        result = "Well done, " + firstName + "! You have passed.";
    } 
    else {
        grade = "Fail";
        result = "Sorry, " + firstName + ". You need to retake this assessment.";
    }
    
    // Display personalized result
    cout << "----------------------------------------" << endl;
    cout << "Student : " << studentName << " (" << studentNumber << ")" << endl;
    cout << "Mark : " << mark << endl;
    cout << "Grade : " << grade << endl;
    cout << "Result : " << result << endl;
    cout << "----------------------------------------" << endl;
    
    return 0;
}