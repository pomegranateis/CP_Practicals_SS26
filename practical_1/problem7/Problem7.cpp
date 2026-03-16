// Running Median — HackerRank
// https://www.hackerrank.com/challenges/find-the-running-median/problem
#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Max-heap for lower half
    priority_queue<double> lowerHalf;
    // Min-heap for upper half
    priority_queue<double, vector<double>, greater<double>> upperHalf;

    cout << fixed << setprecision(1);

    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;

        // Step 1: Insert into correct heap
        if (lowerHalf.empty() || x <= lowerHalf.top())
            lowerHalf.push(x);
        else
            upperHalf.push(x);

        // Step 2: Rebalance so sizes differ by at most 1
        if (lowerHalf.size() > upperHalf.size() + 1) {
            upperHalf.push(lowerHalf.top());
            lowerHalf.pop();
        } else if (upperHalf.size() > lowerHalf.size()) {
            lowerHalf.push(upperHalf.top());
            upperHalf.pop();
        }

        // Step 3: Print running median
        if (lowerHalf.size() == upperHalf.size())
            cout << (lowerHalf.top() + upperHalf.top()) / 2.0 << "\n";
        else
            cout << lowerHalf.top() << "\n";
    }

    return 0;
}