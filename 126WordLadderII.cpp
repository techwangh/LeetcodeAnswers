
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
    	vector<vector<string>> res;
        vector<string> path{beginWord};
        queue<vector<string>> paths;
        paths.push(path);
        vector<string> words;
        int level = 1, minLen = INT_MAX;
        while(!paths.empty()) {
        	path = paths.front();
        	paths.pop();
        	if(path.size() > level) {
        		for(auto w : words) wordList.erase(w);
        		words.clear();
        		level = path.size();
        		if(level >= minLen) break;
        	}

        	string word = path.back();
        	for(int i = 0; i < word.size(); ++i) {
        		string newWord = word;
        		for(char ch = 'a'; ch <= 'z'; ++ch) {
        			newWord[i] = ch;
    				if(wordList.find(newWord) != wordList.end()) {
    					words.push_back(newWord);
    				    vector<string> newPath = path;
    			        newPath.push_back(newWord);
    			        if(newWord == endWord) {
    			        	res.push_back(newPath);
    			        	minLen = newPath.size();
    			        } 
    			        else 
    			        	paths.push(newPath);
    				}
        		}
        	}
        }
        return res;
    }
};


//two pointes, faster
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    	vector<vector<string>> paths;
    	vector<string> path;
    	path.push_back(start);
    	unordered_set<string> words1, words2;
    	words1.insert(start);
    	words2.insert(end);
    	unordered_map<string, vector<string>> nexts;
    	bool words1IsBegin = false;
    	if(searchLadders(words1, words2, dict, nexts, words1IsBegin)) {
    		genLadders(start, end, paths, path, nexts);
    	}
    	return paths;
    }

    bool searchLadders(unordered_set<string>& words1, unordered_set<string>& words2, unordered_set<string>& dict,
    				   unordered_map<string, vector<string>>& nexts, bool& words1IsBegin) {
    	bool reach = false;
    	words1IsBegin = !words1IsBegin;
    	if(words1.empty()) return false;
    	if(words1.size() > words2.size())
    		return searchLadders(words2, words1, dict, nexts, words1IsBegin);
    	for(auto word : words1) dict.erase(word);
    	for(auto word : words2) dict.erase(word);
    	unordered_set<string> words3;
    	for(auto word : words1) {
    		string tmpWord = word;
    		for(auto it = tmpWord.begin(); it != tmpWord.end(); ++it) {
    		    char tmp = *it;
    			for(*it = 'a'; *it <= 'z'; ++(*it)) {
    				if(words2.find(tmpWord) != words2.end()) {
    					reach = true;
    					words1IsBegin ? nexts[word].push_back(tmpWord) : nexts[tmpWord].push_back(word);
    				}
    				else if(!reach && dict.find(tmpWord) != dict.end()) {
    					words3.insert(tmpWord);
    					words1IsBegin ? nexts[word].push_back(tmpWord) : nexts[tmpWord].push_back(word);
    				}
    			}
    			*it = tmp;
    		}
    	}
    	return reach || searchLadders(words2, words3, dict, nexts, words1IsBegin);
    }

    void genLadders(string start, string end, 
    				vector<vector<string>>& paths, vector<string>& path, unordered_map<string, vector<string>>& nexts) {
    	if(start == end) {
    		paths.push_back(path);
    	}
    	else {
    		for(auto word : nexts[start]) {
	    		path.push_back(word);
	    		genLadders(word, end, paths, path, nexts);
	    		path.pop_back();
    		}
    	}
    }
};
