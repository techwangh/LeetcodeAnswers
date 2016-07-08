class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	if(s.empty()) return 0;
        int jstart = 0;
        int maxLength = 1;

        for(int i = 1; i < s.size(); ++i) {
        	for(int j = jstart; j < i; ++j) {
        		if(s[i] == s[j]) {
        			maxLength = max(maxLength, i - jstart);
        			jstart = j + 1;
        			break;
        		}else if(j == i-1) {
        			maxLength = max(maxLength, i - jstart + 1);
        		}
        	}
        }
        return maxLength;
    }
};

//hashTable
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	vector<int> pos(256, 0);
    	int res = 0, left = 0;
    	for(int i = 0; i < s.size(); ++i) {
    		if(pos[s[i]] == 0 || pos[s[i]] < left) {
    			res = max(res, i-left+1);
    		}else {
    			left = pos[s[i]];
    		}
    		pos[s[i]] = i + 1;
    	}
    	return res;
    }
};

//concise one of the above
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	vector<int> pos(256, -1);
    	int res = 0, left = -1;
    	for(int i = 0; i < s.size(); ++i) {
    		left = max(left, pos[s[i]]);
    		res = max(res, i - left);
    		pos[s[i]] = i;
    	}
    	return res;
    }
}