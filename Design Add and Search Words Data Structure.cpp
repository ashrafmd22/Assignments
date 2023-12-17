/*Design Add and Search Words Data Structure

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.*/

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode() {
        isTerminal = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->isTerminal = true;
    }

    bool search(string word) {
        return searchUtil(word, 0, root);
    }

    bool searchUtil( string word, int index, TrieNode* curr) {
        if (index == word.length()) {
            return curr->isTerminal;
        }

        char ch = word[index];
        if (ch == '.') {
            for (auto& child : curr->children) {
                if (searchUtil(word, index + 1, child.second)) {
                    return true;
                }
            }
        } else if (curr->children.find(ch) != curr->children.end()) {
            return searchUtil(word, index + 1, curr->children[ch]);
        }

        return false;
    }
};