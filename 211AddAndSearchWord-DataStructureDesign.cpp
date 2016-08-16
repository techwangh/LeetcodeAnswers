class TrieNode{
public:
	bool isWord;
	TrieNode* children[26];
	TrieNode() : isWord(false) {
		memset(children, 0, sizeof(children));
	}
};

class WordDictionary {
public:

	WordDictionary() : root(new TrieNode()) {}
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* p = root;
		for(auto c : word) {
			int i = c - 'a';
			if(!p->children[i]) p->children[i] = new TrieNode();
			p = p->children[i];
		}
		p->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchWord(word, 0, root);
    }

    bool searchWord(string word, int i, TrieNode* p) {
    	if(i == word.size()) return p->isWord;
    	if(word[i] == '.') {
    		for(auto child : p->children) {
    			if(child && searchWord(word, i+1, child)) return true;
    		}
    		return false;
    	}
    	else 
    		return p->children[word[i]-'a'] && searchWord(word, i+1, p->children[word[i]-'a']);
    }

private:
	TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");