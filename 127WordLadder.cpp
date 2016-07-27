//TLE, don't know whether it is right or not
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    	map<string, bool> isUsed;
    	int res = INT_MAX;
    	for(auto s : wordList)
    		isUsed[s] = false;
        ladderLengthDFS(beginWord, endWord, wordList, isUsed, 0, res);
        return res == INT_MAX ? 0 : res; 
    }

    void ladderLengthDFS(string beginWord, string endWord, unordered_set<string>& wordList, map<string, bool>& isUsed, int curLen, int& minLen) {
    	if(beginWord == endWord) {
    		minLen = min(minLen, curLen+1);
    	}
        else if(getDiff(beginWord, endWord) == 1) {
        	minLen = min(minLen, curLen+2);
        }
        else {
	        for(auto s : wordList) {
	        	if(!isUsed[s] && getDiff(s, endWord) == 1) {
	        		isUsed[s] = true;
	        		ladderLengthDFS(beginWord, s, wordList, isUsed, curLen + 1, minLen);
	        		isUsed[s] = false;
	        	}
	        }
        }
    }

	int getDiff(string s1, string s2) {
		int count = 0;
		for(int i = 0; i < s1.size(); ++i) {
			if(s1[i] != s2[i]) count++;
		}
		return count;
	}
};


class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    	unordered_map<string, int> m;
    	queue<string> q;
    	m[beginWord] = 1;
    	q.push(beginWord);
    	while(!q.empty()) {
    		string word = q.front();
    		q.pop();
    		for(int i = 0; i < word.size(); ++i) {
    			string newWord = word;
    			for(char ch = 'a'; ch <= 'z'; ++ch) {
    				newWord[i] = ch;
    				if(newWord == endWord) return m[word] + 1;
    				if(wordList.find(newWord) != wordList.end() && m.find(newWord) == m.end()) {
    					q.push(newWord);
    					m[newWord] = m[word] + 1;
    				}
    			}
    		}
    	}
    	return 0;
	}
};

//faster, delete visited ones
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
   		queue<string> q;
   		q.push(beginWord);
   		wordList.insert(endWord);
   		wordList.erase(beginWord);
   		int dist = 1;
   		while(!q.empty()) {
   			int end = q.size();
   			for(int i = 0; i < end; ++i) {
	   			string word = q.front();
	   			q.pop();
   				if(word == endWord) return dist;
   				addNextWord(word, wordList, q);
   			}
    		dist++;
   		}
   		return 0;
    }

    void addNextWord(string word, unordered_set<string>& wordList, queue<string>& q) {
    	for(int i = 0; i < word.size(); ++i) {
			string newWord = word;
			for(char ch = 'a'; ch <= 'z'; ++ch) {
				newWord[i] = ch;
				if(wordList.find(newWord) != wordList.end()) {
					q.push(newWord);
					wordList.erase(newWord);
				}
			}
		}
    }
}

//use two pointers, faster
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
  		unordered_set<string> head, tail, *phead, *ptail;
  		head.insert(beginWord);
  		tail.insert(endWord);
  		int dist = 2;
  		while(!head.empty() && !tail.empty()) {
  			if(head.size() <= tail.size()) {
  				phead = &head;
  				ptail = &tail;
  			}
  			else {
  				phead = &tail;
  				ptail = &head;
  			}
  			unordered_set<string> tmp;
  			for(auto word : *phead) {
  				for(int i = 0; i < word.size(); ++i) {
					string newWord = word;
					for(char ch = 'a'; ch <= 'z'; ++ch) {
						newWord[i] = ch;
						if(ptail->find(newWord) != ptail->end()) return dist;
						if(wordList.find(newWord) != wordList.end()) {
							tmp.insert(newWord);
							wordList.erase(newWord);
						}
					}
				}
  			}
  			dist++;
  			*phead = tmp;
  		}
  		return 0;
    }
};
