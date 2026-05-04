#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ─────────────────────────────────────────
//  Manacher's Algorithm
//
//  Finds the longest palindromic substring
//  in O(n) time by:
//   1. Inserting '#' separators to unify
//      odd/even length palindromes.
//   2. Expanding a "mirror" window [l, r]
//      to avoid redundant character checks.
// ─────────────────────────────────────────

string manacher(const string& s) {
    if (s.empty()) return "";

    // ── Step 1: Transform ─────────────────
    // "abc" → "#a#b#c#"
    string t = "#";
    for (char c : s) { t += c; t += '#'; }
    int n = t.size();

    // p[i] = radius of palindrome centred at i in transformed string
    vector<int> p(n, 0);

    int centre = 0, right = 0; // rightmost palindrome boundary so far
    int maxLen = 0, maxCentre = 0;

    // ── Step 2: Fill p[] ──────────────────
    for (int i = 0; i < n; i++) {
        // Mirror of i around current centre
        int mirror = 2 * centre - i;

        if (i < right)
            p[i] = min(right - i, p[mirror]);

        // Try to expand
        int left_i  = i - (p[i] + 1);
        int right_i = i + (p[i] + 1);
        while (left_i >= 0 && right_i < n && t[left_i] == t[right_i]) {
            p[i]++;
            left_i--;
            right_i++;
        }

        // Update centre/right boundary
        if (i + p[i] > right) {
            centre = i;
            right  = i + p[i];
        }

        // Track longest palindrome
        if (p[i] > maxLen) {
            maxLen    = p[i];
            maxCentre = i;
        }
    }

    // ── Step 3: Extract original substring ─
    int start = (maxCentre - maxLen) / 2;
    return s.substr(start, maxLen);
}

// ── Utility: print p[] table ─────────────
void printTable(const string& s) {
    string t = "#";
    for (char c : s) { t += c; t += '#'; }
    int n = t.size();

    vector<int> p(n, 0);
    int centre = 0, right = 0;
    for (int i = 0; i < n; i++) {
        int mirror = 2 * centre - i;
        if (i < right) p[i] = min(right - i, p[mirror]);
        int l = i - (p[i] + 1), r = i + (p[i] + 1);
        while (l >= 0 && r < n && t[l] == t[r]) { p[i]++; l--; r++; }
        if (i + p[i] > right) { centre = i; right = i + p[i]; }
    }

    cout << "Transformed: " << t << "\n";
    cout << "Index:       ";
    for (int i = 0; i < n; i++) cout << i % 10;
    cout << "\n";
    cout << "p[]:         ";
    for (int i = 0; i < n; i++) cout << p[i];
    cout << "\n";
}

// ─────────────────────────────────────────
//  Main — Demo
// ─────────────────────────────────────────
int main() {
    vector<string> tests = {
        "babad",
        "cbbd",
        "racecar",
        "abacaba",
        "aabbaa",
        "a",
        "madam",
        "abcde"
    };

    cout << "=== MANACHER'S ALGORITHM ===\n\n";
    for (const string& s : tests) {
        string result = manacher(s);
        cout << "Input:   \"" << s << "\"\n";
        printTable(s);
        cout << "Longest Palindromic Substring: \"" << result
             << "\"  (length " << result.size() << ")\n";
        cout << string(50, '-') << "\n";
    }

    return 0;
}