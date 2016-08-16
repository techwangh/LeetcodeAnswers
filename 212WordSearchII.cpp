//TLE
class Solution {
public:
	vector<vector<bool>> visited;
	int m, n;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> res;
    	if(board.empty() || board[0].empty()) return vector<string>(res.begin(), res.end());
        m = board.size(), n = board[0].size();
        visited.resize(m, vector<bool>(n, false));

        for(int i = 0; i < m; ++i) {
        	for(int j = 0; j < n; ++j) {
        		dfs(board, words, res, 0, i,j);
        	}
        }
        return vector<string>(res.begin(), res.end());
    }

    void dfs(vector<vector<char>>& board, vector<string> words, unordered_set<string>& res, int index, int i, int j) {
    	if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || words.empty()) return;
    	visited[i][j] = true;

    	
    	vector<string> next_words;
    	for(auto word : words) {
    		if(index < word.size() && word[index] == board[i][j]) {
    			if(index+1 == word.size()) 
    				res.insert(word);
    			else
    				next_words.push_back(word);
    		}
    	}

    	dfs(board, next_words, res, index+1, i-1, j);
    	dfs(board, next_words, res, index+1, i+1, j);
    	dfs(board, next_words, res, index+1, i, j-1);
    	dfs(board, next_words, res, index+1, i, j+1);

    	visited[i][j] = false;
    }
};


//use Tire
class Solution {
public:
	struct TrieNode {
		string word;
		TrieNode* child[26];
		TrieNode() {
		    mwmset(child, 0, sizeof(child));
		}
	};

	struct Trie {
	    TrieNode* root;
		Trie() : root(new TrieNode()) {}
		~Trie() { freeNode(root); }

		void insert(string word) {
			TrieNode* p = root;
			for(auto c : word) {
				int i = c - 'a';
				if(!p->child[i]) p->child[i] = new TrieNode();
				p = p->child[i];
			}
			p->word = word;
		}

	private:
		freeNode(TrieNode* node) {
			for(int i = 0; i < 26; ++i) {
				if(node->child[i])
					freeNode(node->child[i]);
			}
			delete node;
		}
	};

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		 vector<string> res;
		 m = board.size();
		 n = board[0].size();
		 visited.resize(m, vector<bool>(n, false));
		 Trie T;
		 for(auto word : words) T.insert(word);
		 
		 for(int i = 0; i < m; ++i) {
		 	for(int j = 0; j < n; ++j) {
	 			dfs(board, res, T.root, i, j);
		 	}
		}
		return res;
    }

    void dfs(vector<vector<char>>& board, vector<string>& res, TrieNode* p, int i, int j) {
    	if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) return;
    	p = p->child[board[i][j] - 'a'];
    	if(!p) return;

    	if(!p->word.empty()) {
    		res.push_back(p->word);
    		p->word.clear();
    	}

    	visited[i][j] = true;
    	dfs(board, res, p, i-1, j);
    	dfs(board, res, p, i+1, j);
    	dfs(board, res, p, i, j-1);
    	dfs(board, res, p, i, j+1);
    	visited[i][j] = false;
    }

private:
	int m, n;
	vector<vector<bool>> visited;
};