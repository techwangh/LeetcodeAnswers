//TLE
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
    	if(s.empty()) return true;
        for(int l = 1; l <= s.size(); ++l) {
    		string str = s.substr(0, l);
    		if(wordDict.find(str) != wordDict.end())  {
    			if(wordBreak(s.substr(l), wordDict)) return true;
    		}
        }
        return false;
    }
};

//DP
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
   		vector<bool> canBreak(s.size()+1, false);
   		canBreak[0] = true;
   		for(int i = 1; i <= s.size(); ++i) {
   			for(int j = 0; j < i; ++j) {
   				if(canBreak[j] && wordDict.find(s.substr(j, i-j)) != wordDict.end()) {
   					canBreak[i] = true;
   					break;
   				}
   			}
   		}
   		return canBreak.back();
    }
};