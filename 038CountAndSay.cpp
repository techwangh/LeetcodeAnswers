class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        int count = 1;
        for(int i = 1; i < n; ++i) {
        	string tmp = "";
        	for(int j = 0; j < s.size(); ++j) {
        		if(j < s.size()-1 && s[j+1] == s[j]) 
        			count++;
        		else {
        			tmp.push_back('0'+count);
        			tmp.push_back(s[j]);
        			count = 1;
        		}
        	}
        	s = tmp;
        }
        return s;
    }
};