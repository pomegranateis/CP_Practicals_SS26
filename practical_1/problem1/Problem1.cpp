#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nMaximum: " << *max_element(arr.begin(), arr.end()) << endl;
    cout << "Minimum: " << *min_element(arr.begin(), arr.end()) << endl;
    cout << "Sum:     " << accumulate(arr.begin(), arr.end(), 0) << endl;

    return 0;
}