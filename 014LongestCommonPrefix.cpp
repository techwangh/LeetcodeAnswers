class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int count = 0;
        for(int i = 0; i < strs[0].size(); ++i) {
        	char val = strs[0][i];
        	for(string str : strs) {
        		if(i >= str.size() || str[i] != val) return str.substr(0,count);
        	}
        	count++;
        }
        return strs[0];
    }
};