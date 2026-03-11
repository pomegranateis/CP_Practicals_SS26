//================================================
// Q07: Array Operations & Statistics
// Arrays, loops, and statistical calculations
//================================================

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string studentName = "Pema Tshering Yangchen";
    int studentNumber = 2230295;
    
    // Array named using first name with 5 test marks
    int pema_marks[5] = {88, 76, 91, 65, 83};
    
    cout << "Student: " << studentName << " | No: " << studentNumber << endl;
    cout << "------------------------------------------" << endl;
    cout << "Index Mark Bar" << endl;
    
    // Initialize variables for statistics
    int highest = pema_marks[0];
    int lowest = pema_marks[0];
    int sum = 0;
    
    // Display marks with index and bar chart
    for (int i = 0; i < 5; i++) {
        cout << "[" << i << "] " << setw(3) << pema_marks[i] << " ";
        
        // Create bar chart (one * per 10 marks)
        int stars = pema_marks[i] / 10;
        for (int j = 0; j < stars; j++) {
            cout << "*";
        }
        cout << endl;
        
        // Update statistics
        sum += pema_marks[i];
        if (pema_marks[i] > highest) highest = pema_marks[i];
        if (pema_marks[i] < lowest) lowest = pema_marks[i];
    }
    
    // Calculate average and count marks above average
    double average = sum / 5.0;  // Use 5.0 to get decimal result
    int aboveAverage = 0;
    for (int i = 0; i < 5; i++) {
        if (pema_marks[i] > average) {
            aboveAverage++;
        }
    }
    
    // Display statistics
    cout << "------------------------------------------" << endl;
    cout << "Highest : " << highest << endl;
    cout << "Lowest : " << lowest << endl;
    cout << "Average : " << fixed << setprecision(2) << average << endl;
    cout << "Above Average: " << aboveAverage << " mark(s)" << endl;
    
    return 0;
}