class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        restoreIpAddressesDFS(s, res, "", 1);
        return res;
    }

    void restoreIpAddressesDFS(string s, vector<string>& res, string out, int level) {
    	if(level == 5) {
    		if(s.empty()) 
    			res.push_back(out);
    		return;
    	}
    	if(level != 1) out += ".";
    	for(int i = 1; i <= 3; ++i) {
    		if(s.size() >= i && isValid(s.substr(0,i))) {
    			restoreIpAddressesDFS(s.substr(i), res, out+s.substr(0,i), level+1);
    		}
    	}
    }

    bool isValid(string s) {
        if(s.size() > 1 && s[0] == '0') return false;
    	int val = atoi(s.c_str());
    	return val <= 255 && val >= 0;
    }
};