#include <iostream>
#include <deque>
#include <string>
using namespace std;

void printDeque(const deque<int>& dq) {
    cout << "Line: [";
    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i];
        if (i + 1 < dq.size()) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    deque<int> line;
    int ops;
    cout << "Enter number of operations: ";
    cin >> ops;
    cin.ignore();

    for (int i = 0; i < ops; i++) {
        string op;
        cout << "Operation: ";
        getline(cin, op);

        if (op.substr(0, 10) == "push_front") {
            int x = stoi(op.substr(11));
            line.push_front(x);
        } else if (op.substr(0, 9) == "push_back") {
            int x = stoi(op.substr(10));
            line.push_back(x);
        } else if (op == "pop_front") {
            if (!line.empty()) line.pop_front();
            else cout << "  Line is empty!" << endl;
        } else if (op == "pop_back") {
            if (!line.empty()) line.pop_back();
            else cout << "  Line is empty!" << endl;
        } else {
            cout << "  Unknown operation." << endl;
        }

        printDeque(line);
    }

    return 0;
}