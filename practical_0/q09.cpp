//================================================
// Q09: Vector & Dynamic Collections
// STL vectors and algorithms
//================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

int main() {
    // Declare vector named using student number
    vector<int> v2230295;
    
    // Get 6 values from user
    cout << "Enter 6 values: ";
    for (int i = 0; i < 6; i++) {
        int value;
        cin >> value;
        v2230295.push_back(value);
    }
    
    // Display original vector
    cout << "Original : ";
    for (int val : v2230295) {
        cout << val << " ";
    }
    cout << endl;
    
    // Sort vector in ascending order
    sort(v2230295.begin(), v2230295.end());
    cout << "Sorted : ";
    for (int val : v2230295) {
        cout << val << " ";
    }
    cout << endl;
    
    // Find minimum, maximum, and sum using STL algorithms
    int minVal = *min_element(v2230295.begin(), v2230295.end());
    int maxVal = *max_element(v2230295.begin(), v2230295.end());
    int sum = accumulate(v2230295.begin(), v2230295.end(), 0);
    double average = sum / 6.0;
    
    cout << "Min : " << minVal << endl;
    cout << "Max : " << maxVal << endl;
    cout << "Sum : " << sum << endl;
    cout << "Average : " << fixed << setprecision(2) << average << endl;
    
    // Remove all values below average
    v2230295.erase(
        remove_if(v2230295.begin(), v2230295.end(), 
                  [average](int x) { return x < average; }), 
        v2230295.end()
    );
    
    cout << "After removing below average:" << endl;
    for (int val : v2230295) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}