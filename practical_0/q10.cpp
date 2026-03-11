//================================================
// Q10: Classes & Object-Oriented Design
// Encapsulation, constructors, and methods
//================================================

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

// Student class definition
class Student {
private:
    // Private attributes (encapsulation)
    string name;
    int studentNumber;
    vector<float> marks;

public:
    // Parameterized constructor
    Student(string n, int sn) : name(n), studentNumber(sn) {}
    
    // Add a mark to the student's record
    void addMark(float m) {
        marks.push_back(m);
    }
    
    // Calculate average of all marks
    float getAverage() {
        if (marks.empty()) return 0.0;
        float sum = accumulate(marks.begin(), marks.end(), 0.0);
        return sum / marks.size();
    }
    
    // Find highest mark
    float getHighest() {
        if (marks.empty()) return 0.0;
        return *max_element(marks.begin(), marks.end());
    }
    
    // Find lowest mark
    float getLowest() {
        if (marks.empty()) return 0.0;
        return *min_element(marks.begin(), marks.end());
    }
    
    // Print complete academic report
    void printReport() {
        cout << "================================================" << endl;
        cout << " ACADEMIC REPORT" << endl;
        cout << "================================================" << endl;
        cout << "Student Name : " << name << endl;
        cout << "Student No : " << studentNumber << endl;
        cout << "Marks Entered : " << marks.size() << endl;
        
        cout << "Marks : ";
        for (float mark : marks) {
            cout << (int)mark << " ";
        }
        cout << endl;
        
        float avg = getAverage();
        cout << "Average : " << fixed << setprecision(2) << avg << endl;
        cout << "Highest : " << (int)getHighest() << endl;
        cout << "Lowest : " << (int)getLowest() << endl;
        
        // Determine classification based on average
        string classification;
        if (avg >= 75) classification = "Distinction";
        else if (avg >= 60) classification = "Merit";
        else if (avg >= 40) classification = "Pass";
        else classification = "Fail";
        
        cout << "Classification: " << classification << endl;
        cout << "================================================" << endl;
    }
};

int main() {
    // Create Student object using constructor
    Student student("Pema Tshering Yangchen", 2230295);
    
    // Add marks using addMark method
    // CHANGE THESE MARKS AS DESIRED
    student.addMark(88);
    student.addMark(76);
    student.addMark(91);
    student.addMark(65);
    student.addMark(83);
    
    // Display complete academic report
    student.printReport();
    
    return 0;
}