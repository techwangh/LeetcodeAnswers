class Solution {
public:
    string convert(string s, int numRows) {
        string res = "";
        int inc = 2*numRows - 2;
        for(int i = 0; i < numRows; ++i) {
        	for(j = i; j < s.size(); j += inc) {
        		res += s[j];
        		int tmp = j + inc - 2*i;
        		if(i != 0 && i != numRows-1 && tmp < s.size())
        			res += s[tmp];
        	}
        }
        return res;
    }
};