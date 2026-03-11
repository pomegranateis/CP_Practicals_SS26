//================================================
// Q08: Function Design & Modular Programming
// Custom functions with different return types
//================================================

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function prototypes (declarations)
int digitSum(int n);
bool isPrime(int n);
int countVowels(string s);
string reverseString(string s);

// Function definitions

// Calculate sum of digits in a number
int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // Check divisors up to square root
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Count vowels in a string
int countVowels(string s) {
    int count = 0;
    for (char c : s) {
        char lower = tolower(c);
        if (lower == 'a' || lower == 'e' || lower == 'i' || 
            lower == 'o' || lower == 'u') {
            count++;
        }
    }
    return count;
}

// Reverse a string
string reverseString(string s) {
    string reversed = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        reversed += s[i];
    }
    return reversed;
}

int main() {
    string fullName = "Pema Tshering Yangchen";
    int studentNumber = 2230295;
    
    // Display formatted results
    cout << "========================================" << endl;
    cout << " Function Results for " << fullName << endl;
    cout << " Student No: " << studentNumber << endl;
    cout << "========================================" << endl;
    
    cout << "digitSum(" << studentNumber << ") : " << digitSum(studentNumber) << endl;
    cout << "isPrime(" << studentNumber << ") : " << (isPrime(studentNumber) ? "Yes" : "No") << endl;
    cout << "countVowels(" << fullName << ") : " << countVowels(fullName) << endl;
    cout << "reverseString(" << fullName << "): " << reverseString(fullName) << endl;
    
    cout << "========================================" << endl;
    
    return 0;
}