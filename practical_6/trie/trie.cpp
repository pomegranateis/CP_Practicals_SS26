#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// ─────────────────────────────────────────
//  Trie Node
// ─────────────────────────────────────────
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

// ─────────────────────────────────────────
//  Trie Class
// ─────────────────────────────────────────
class Trie {
private:
    TrieNode* root;

    // Helper: recursively delete nodes
    void deleteNode(TrieNode* node) {
        for (auto& pair : node->children)
            deleteNode(pair.second);
        delete node;
    }

    // Helper: recursive deletion of a word
    bool deleteHelper(TrieNode* node, const string& word, int depth) {
        if (!node) return false;

        if (depth == (int)word.size()) {
            if (!node->isEndOfWord) return false;
            node->isEndOfWord = false;
            return node->children.empty(); // safe to delete if no children
        }

        char ch = word[depth];
        if (node->children.find(ch) == node->children.end())
            return false;

        bool shouldDelete = deleteHelper(node->children[ch], word, depth + 1);

        if (shouldDelete) {
            delete node->children[ch];
            node->children.erase(ch);
            return node->children.empty() && !node->isEndOfWord;
        }

        return false;
    }

public:
    Trie() { root = new TrieNode(); }
    ~Trie() { deleteNode(root); }

    // ── INSERT ─────────────────────────────
    void insert(const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end())
                curr->children[ch] = new TrieNode();
            curr = curr->children[ch];
        }
        curr->isEndOfWord = true;
        cout << "[INSERT] \"" << word << "\" inserted.\n";
    }

    // ── SEARCH ─────────────────────────────
    bool search(const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end())
                return false;
            curr = curr->children[ch];
        }
        return curr->isEndOfWord;
    }

    // ── DELETE ─────────────────────────────
    bool remove(const string& word) {
        return deleteHelper(root, word, 0);
    }
};

// ─────────────────────────────────────────
//  Main — Demo
// ─────────────────────────────────────────
int main() {
    Trie trie;

    cout << "=== TRIE: INSERT ===\n";
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apt");
    trie.insert("bat");
    trie.insert("ball");

    cout << "\n=== TRIE: SEARCH ===\n";
    string toSearch[] = {"apple", "app", "ap", "bat", "cat"};
    for (const string& w : toSearch) {
        cout << "[SEARCH] \"" << w << "\": "
             << (trie.search(w) ? "FOUND" : "NOT FOUND") << "\n";
    }

    cout << "\n=== TRIE: DELETE ===\n";
    string toDelete[] = {"app", "bat", "xyz"};
    for (const string& w : toDelete) {
        bool deleted = trie.remove(w);
        cout << "[DELETE] \"" << w << "\": "
             << (deleted ? "Deleted (node removed)" : "Deleted (shared prefix kept) or Not Found") << "\n";
    }

    cout << "\n=== TRIE: SEARCH AFTER DELETE ===\n";
    string recheck[] = {"apple", "app", "apt", "bat"};
    for (const string& w : recheck) {
        cout << "[SEARCH] \"" << w << "\": "
             << (trie.search(w) ? "FOUND" : "NOT FOUND") << "\n";
    }

    return 0;
}