class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(s.size() == 0 || words.size() == 0 || words[0].size() == 0)
        	return res;
        unordered_map<string, int> map1;
        int m = words.size(), n = words[0].size();
        for(auto word : words) 
        	map1[word]++;
        for(int i = 0; i < s.size()-m*n; ++i) {
        	unordered_map<string, int> map2;
        	for(int j = 0; j < m; ++j) {
        		string str = s.substr(i+j*m, m);
        		if(map1.find(str) == map1.end()) break;
        		map2[str]++;
        		if(map2[str] > map1[str]) break;
        	}
        	if(j == m) 
        		res.push_back(i);
        }
        return res;
    }
};

//O(n)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(s.size() == 0 || words.size() == 0 || words[0].size() == 0)
        	return res;
        unordered_map<string, int> dict;
        int wordLen = words[0].size();
        for(auto word : words) 
        	dict[word]++;  
        for(int i = 0; i < wordLen; ++i) {
        	int left = i, count = 0;
        	unordered_map<string, int> tmpDict;
        	for(int j = i; j <= int(s.size())-wordLen; j+=wordLen) {
        		string str = s.substr(j, wordLen);
        		if(dict.find(str) != dict.end()) {
        			tmpDict[str]++;
        			if(tmpDict[str] <= dict[str])
        				count++;
        			else {		//窗口右移
	        			while(tmpDict[str] > dict[str]) {
	        				string tmpStr = s.substr(left, wordLen);
	        				tmpDict[tmpStr]--;
	        				if(tmpDict[tmpStr] < dict[tmpStr])
	        					count--;
	        				left += wordLen;
	        			}
        			}
        			if(count == words.size()) {
        				res.push_back(left);
        				tmpDict[s.substr(left, wordLen)]--;
        				count--;
        				left += wordLen;
        			}
        		} else {
        			tmpDict.clear();
        			count = 0;
        			left = j + wordLen;
        		}
        	}
        } 
        return res;
    }
};
