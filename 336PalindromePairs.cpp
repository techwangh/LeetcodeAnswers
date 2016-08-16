//O(k*n^2), n = words.size(), k = words[i].size();
//TLE
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        for(int i = 0; i < words.size(); ++i) {
        	for(int j = 0; j < words.size(); ++j) {
        		if(i == j) continue;
        		if(isPalindrome(words[i] + words[j]))
        			res.push_back({i, j});
        	}
        }
        return res;
    }

    bool isPalindrome(string s) {
    	int left = 0, right = s.size()-1;
    	while(left < right) {
    		if(s[left++] != s[right--]) return false;
    	}
    	return true;
    }
};

//O(n*k^2)
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> m;
        for(int i = 0; i < words.size(); ++i) {
        	string word = words[i];
        	reverse(word.begin(), word.end());
        	m[word] = i;
        }

        for(int i = 0; i < words.size(); ++i) {
        	for(int j = 0; j < word[i].size(); ++j) {
        		string left = words[i].substr(0, j);
        		string right = words[i].substr(j);

        		if(m.find(left) != m.end() && isPalindrome(right) && m[left] != i) {
        			res.push_back({i, m[left]});
        			if(left == "") 
        				res.push_back({m[left], i});
        		}
        		if(m.find(right) != m.end() && isPalindrome(left) && m[right] != i) {
        			res.push_back({m[right], i});
        		}
        	}
        }
    }

    bool isPalindrome(string s) {
    	int left = 0, right = s.size()-1;
    	while(left < right) {
    		if(s[left++] != s[right--]) return false;
    	}
    	return true;
    } 
};