#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cout << "Enter N and K: ";
    cin >> n >> k;

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    priority_queue<int> maxHeap(arr.begin(), arr.end());

    cout << "Top " << k << " largest elements: ";
    for (int i = 0; i < k && !maxHeap.empty(); i++) {
        cout << maxHeap.top();
        if (i + 1 < k) cout << " ";
        maxHeap.pop();
    }
    cout << endl;

    return 0;
}