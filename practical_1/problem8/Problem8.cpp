#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int total = 1 << n; // 2^n subsets

    cout << "All subsets:" << endl;
    for (int mask = 0; mask < total; mask++) {
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))  // check if bit i is set
                cout << arr[i] << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}