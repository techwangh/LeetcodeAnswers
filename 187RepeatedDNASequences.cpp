class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.size() <= 10) return res;
        unordered_map<string, int> m;
        for(int i = 0; i <= s.size()-10; ++i) {
        	string str = s.substr(i, 10);
        	if(m.find(str) != m.end()) {
        		if(m[str] == 1) {
        			res.push_back(str);
        			m[str]++;
        		}
        	}
        	else {
        		m[str] = 1;
        	}
        }
        return res;
    }
};



class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.size() <= 10) return res;
        unordered_map<int, int> m;
  		int i = 0, cur = 0, mask = 0x7ffffff; 
  		for(i = 0; i < 9; ++i) {
  			cur = (cur << 3) | (s[i] & 7);
  		}
  		while(i < s.size()) {
  			cur = ((cur&mask) << 3) | (s[i++] & 7);
  			if(m.find(cur) != m.end()) {
  				if(m[cur] == 1) {
  					res.push_back(s.substr(i-10, 10));
  					m[cur]++;
  				}
  			}
  			else {
  				m[cur] = 1;
  			}
  		}
  		return res;
    }
};