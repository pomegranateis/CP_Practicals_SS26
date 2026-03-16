// Count subsets with sum equal to target
// Reference: https://www.geeksforgeeks.org/dsa/count-of-subsets-with-sum-equal-to-x/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, target;
    cout << "Enter N: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> target;

    int total = 1 << n;
    int count = 0;

    for (int mask = 0; mask < total; mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                sum += arr[i];
        if (sum == target)
            count++;
    }

    cout << "Number of subsets with sum " << target << ": " << count << endl;

    return 0;
}