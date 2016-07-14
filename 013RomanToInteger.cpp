class Solution {
public:
    int romanToInt(string s) {
    	int res = 0;
        map<char, int> dic;
        dic['I'] = 1;
        dic['V'] = 5;
        dic['X'] = 10;
        dic['L'] = 50;
        dic['C'] = 100;
        dic['D'] = 500;
        dic['M'] = 1000;
        for(int i = 0; i < s.size(); ++i) {
        	if(i == s.size() || dic[s[i]] >= dic[s[i+1]])
        		res += dic[s[i]];
        	else
        		res -= dic[s[i]];
        }
        return res;
    }
};