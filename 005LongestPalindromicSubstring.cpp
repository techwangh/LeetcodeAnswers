//DP, TLE
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int left = 0, right = 0;
        int maxLength = 0;
        for(int i = 0; i < s.size(); ++i) {
        	dp[i][i] = true;
        }
        for(int l = 2; l <= s.size(); ++l) {
        	for(int i = 0; i <= s.size()-l; ++i) {
        		int j = i + l -1;
        		dp[i][j] = s[i] == s[j] && (j-i < 2 || dp[i+1][j-1]);
        		if(dp[i][j] && j-i+1 > maxLength) {
        		    maxLength = j-i+1;
        		    left = i;
        		    right = j;
        		}
        	}
        }
        return s.substr(left, right-left+1);
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
    	if(s.size() <= 1) return s;
		int start = 0, maxLength = 0;
		for(int i = 0; i < s.size(); ) {
		    if(s.size()-i <= maxLength/2) break;
			int j = i, k = i;
			while(k < s.size()-1 && s[k] == s[k+1])     //skip duplicate characters
				++k;	
			i = k + 1;	
			while(j > 0 && k < s.size()-1 && s[k+1] == s[j-1]) {	//expand
				++k;
				--j;
			}
			int newLength = k - j + 1;
			if(maxLength < newLength) {
				maxLength = newLength;
				start = j;
			}
		}    
		return s.substr(start, maxLength);
	}
};
