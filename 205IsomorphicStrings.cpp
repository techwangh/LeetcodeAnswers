class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m;
        for(int i = 0; i < s.size(); ++i) {
        	if(m.find(s[i]) != m.end()) {
        	    if(m[s[i]] != t[i]) return false;
        	}
        	else {
        	    for(auto pair : m) {
        	        if(t[i] == pair.second) return false;
        	    }
        	    m[s[i]] = t[i];
        	}
        }
        return true;
    }
};


class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	vector<int> cs(256, 0), ct(256, 0);
    	for(int i = 0; i < s.size(); ++i) {
    		if(cs[s[i]] != ct[t[i]]) return false;
    		cs[s[i]] = i+1;
    		ct[t[i]] = t+1;
    	}
    	return true;
    }
};