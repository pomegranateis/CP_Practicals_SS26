//================================================
// Q03: String Manipulation & Analysis
// String methods and character operations
//================================================

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string fullName = "Pema Tshering Yangchen";  // CHANGE TO YOUR NAME

    // 1. Total character count including spaces
    int totalLength = fullName.length();
    
    // 2. Convert to uppercase and lowercase
    string uppercase = fullName;
    string lowercase = fullName;
    transform(uppercase.begin(), uppercase.end(), uppercase.begin(), ::toupper);
    transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
    
    // 3. Extract initials
    string initials = "";
    initials += toupper(fullName[0]); // First character
    for (int i = 1; i < fullName.length(); i++) {
        if (fullName[i-1] == ' ') {
            initials += '.';
            initials += toupper(fullName[i]);
        }
    }
    initials += '.';
    
    // 4. Length of first name only
    int spacePos = fullName.find(' ');
    string firstName = fullName.substr(0, spacePos);
    int firstNameLen = firstName.length();
    
    // Display results
    cout << "Full Name : " << fullName << endl;
    cout << "Total Length : " << totalLength << endl;
    cout << "Uppercase : " << uppercase << endl;
    cout << "Lowercase : " << lowercase << endl;
    cout << "Initials : " << initials << endl;
    cout << "First Name Len : " << firstNameLen << endl;
    
    return 0;
}
