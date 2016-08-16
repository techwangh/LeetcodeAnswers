class TrieNode {
public:
    bool isWord;
    unordered_map(char, TrieNode*) child;
    
    // Initialize your data structure here.
    TrieNode() : isWord(false), child() {}
    
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for(auto c : word) {
            if(p->child.find(c) == p->child.end()) p->child[c] = new TrieNode();
            p = p->child[c];
        }
        p->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = find(word);
        return p != nullptr && p->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = find(prefix);
        return p != nullptr;        
    }

    TrieNode* find(string word) {
        TrieNode* p = root;
        for(auto c : word) {
            if(p->child.find(c) == p->child.end()) return nullptr;
            p = p->child[c];
        }
        return p;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");




class TrieNode {
public:
    bool isWord;
    TrieNode* child[26];
    // Initialize your data structure here.
    TrieNode() : isWord(false) {
        for(auto &a : child) {
            a = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for(auto c : word) {
            int i = c - 'a';
            if(!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = find(word);
        return p != nullptr && p->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = find(word);
        return p != nullptr;
    }

    TrieNode* find(string word) {
        TrieNode* p = root;
        for(auto c : word) {
            if(!p->child[c-'a']) return nullptr;
            p = p->child[c-'a'];
        }
        return p;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");