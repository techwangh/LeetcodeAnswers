//TLE
class Solution {
public:
    string shortestPalindrome(string s) {
        int i = 0, n = s.size();
        for(i = n; i > 0; --i) {
        	if(isPalindrome(s.substr(0, i))) break;
        }
        string tmp = s.substr(i);
        reverse(tmp.begin(), tmp.end());
        return tmp + s;
    }

    bool isPalindrome(string s) {
    	int left = 0, right = s.size()-1;
    	while(left < right) {
    		if(s[left++] != s[right--]) return false;
    	}
    	return true;
    }
};


class Solution {
public:
    string shortestPalindrome(string s) {
   		string rev_s = s;
   		reverse(rev_s.begin(), rev_s.end());
   		string l = s + "#" + rev_s;
   		vector<int> p(l.size());
   		for(int i = 1; i < l.size(); ++i) {
   			int j = p[i-1];
   			while(j > 0 && l[i] != l[j]) j = p[j-1];
   			p[i] = j + (l[i] == l[j]);
   		}
   		return rev_s.substr(0, s.size()-p.back()) + s;
    }
};