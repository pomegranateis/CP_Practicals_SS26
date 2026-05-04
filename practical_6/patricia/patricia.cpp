#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ─────────────────────────────────────────
//  PATRICIA (Practical Algorithm To Retrieve
//  Information Coded In Alphanumeric) Trie
//
//  Each node stores a "bit index" that tells
//  which bit of the key to branch on. Back-
//  edges (pointing upward/to self) mark where
//  a search terminates.
// ─────────────────────────────────────────

// Return the k-th bit (0-indexed from MSB) of a string
int getBit(const string& key, int bit) {
    int byteIdx = bit / 8;
    int bitIdx  = 7 - (bit % 8);
    if (byteIdx >= (int)key.size()) return 0;
    return (key[byteIdx] >> bitIdx) & 1;
}

// Find the first bit position where two strings differ
int firstDifferentBit(const string& a, const string& b) {
    int maxLen = max(a.size(), b.size()) * 8;
    for (int i = 0; i < maxLen; i++)
        if (getBit(a, i) != getBit(b, i))
            return i;
    return maxLen;
}

// ─────────────────────────────────────────
//  Node
// ─────────────────────────────────────────
struct PatriciaNode {
    string key;
    int bitIndex;          // which bit determines branching
    PatriciaNode* left;    // bit == 0
    PatriciaNode* right;   // bit == 1

    PatriciaNode(const string& k, int bit)
        : key(k), bitIndex(bit), left(nullptr), right(nullptr) {}
};

// ─────────────────────────────────────────
//  PATRICIA Trie Class
// ─────────────────────────────────────────
class PatriciaTrie {
private:
    PatriciaNode* root;

    // Follow the trie until a back-edge is reached
    PatriciaNode* searchNode(const string& key) {
        if (!root) return nullptr;
        PatriciaNode* prev = root;
        PatriciaNode* curr = (getBit(key, root->bitIndex) == 0)
                             ? root->left : root->right;
        while (curr && curr->bitIndex > prev->bitIndex) {
            prev = curr;
            curr = (getBit(key, curr->bitIndex) == 0)
                   ? curr->left : curr->right;
        }
        return curr;
    }

    void collectAll(PatriciaNode* node, int parentBit, vector<string>& result) {
        if (!node) return;
        if (node->bitIndex <= parentBit) return; // back-edge
        result.push_back(node->key);
        collectAll(node->left,  node->bitIndex, result);
        collectAll(node->right, node->bitIndex, result);
    }

public:
    PatriciaTrie() : root(nullptr) {}

    // ── INSERT ─────────────────────────────
    void insert(const string& key) {
        if (!root) {
            root = new PatriciaNode(key, -1);
            root->left = root; // back-edge to itself
            cout << "[INSERT] \"" << key << "\" (root)\n";
            return;
        }

        PatriciaNode* found = searchNode(key);
        if (found && found->key == key) {
            cout << "[INSERT] \"" << key << "\" already exists.\n";
            return;
        }

        string existing = found ? found->key : "";
        int diffBit = firstDifferentBit(key, existing);

        // Find insertion point (where bitIndex would fit)
        PatriciaNode* prev = root;
        PatriciaNode* curr = (getBit(key, root->bitIndex) == 0)
                             ? root->left : root->right;

        while (curr && curr->bitIndex > prev->bitIndex &&
               curr->bitIndex < diffBit) {
            prev = curr;
            curr = (getBit(key, curr->bitIndex) == 0)
                   ? curr->left : curr->right;
        }

        PatriciaNode* newNode = new PatriciaNode(key, diffBit);

        // Self-referencing back-edge
        if (getBit(key, diffBit) == 1) {
            newNode->left  = curr;
            newNode->right = newNode;
        } else {
            newNode->left  = newNode;
            newNode->right = curr;
        }

        // Attach newNode to parent
        if (getBit(key, prev->bitIndex) == 0)
            prev->left  = newNode;
        else
            prev->right = newNode;

        cout << "[INSERT] \"" << key << "\" at bit " << diffBit << "\n";
    }

    // ── SEARCH ─────────────────────────────
    bool search(const string& key) {
        PatriciaNode* node = searchNode(key);
        return node && node->key == key;
    }

    // ── DELETE ─────────────────────────────
    // Simplified: mark as empty string (tombstone)
    // Full structural deletion in PATRICIA is complex;
    // this mirrors standard educational implementations.
    bool remove(const string& key) {
        PatriciaNode* node = searchNode(key);
        if (!node || node->key != key) return false;
        node->key = ""; // tombstone
        return true;
    }

    // ── PRINT ALL KEYS ─────────────────────
    void printAll() {
        vector<string> keys;
        if (root && root->left != root)
            collectAll(root->left, root->bitIndex, keys);
        else if (root)
            keys.push_back(root->key);
        cout << "Keys in trie: ";
        for (const string& k : keys)
            if (!k.empty()) cout << "\"" << k << "\" ";
        cout << "\n";
    }
};

// ─────────────────────────────────────────
//  Main — Demo
// ─────────────────────────────────────────
int main() {
    PatriciaTrie pt;

    cout << "=== PATRICIA: INSERT ===\n";
    pt.insert("apple");
    pt.insert("app");
    pt.insert("apt");
    pt.insert("bat");
    pt.insert("ball");

    cout << "\n=== PATRICIA: SEARCH ===\n";
    string toSearch[] = {"apple", "app", "ap", "bat", "cat"};
    for (const string& w : toSearch)
        cout << "[SEARCH] \"" << w << "\": "
             << (pt.search(w) ? "FOUND" : "NOT FOUND") << "\n";

    cout << "\n=== PATRICIA: DELETE ===\n";
    string toDelete[] = {"app", "bat", "xyz"};
    for (const string& w : toDelete) {
        bool ok = pt.remove(w);
        cout << "[DELETE] \"" << w << "\": "
             << (ok ? "Removed (tombstoned)" : "Not Found") << "\n";
    }

    cout << "\n=== PATRICIA: SEARCH AFTER DELETE ===\n";
    string recheck[] = {"apple", "app", "apt", "bat"};
    for (const string& w : recheck)
        cout << "[SEARCH] \"" << w << "\": "
             << (pt.search(w) ? "FOUND" : "NOT FOUND") << "\n";

    return 0;
}