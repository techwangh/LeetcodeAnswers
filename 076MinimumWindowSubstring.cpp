class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        int len = INT_MAX, start = 0, head = 0;
        for(char c : t) 
        	m[c]++;
        int count = t.size();
        for(int i = 0; i < s.size(); ++i) {
        	if(m.find(s[i]) != m.end()) {
        		m[s[i]]--;
        		if(m[s[i]] >= 0) count--;
        	}
        	while(count == 0) {
        	    if(m.find(s[start]) != m.end()) {
        			m[s[start]]++;
        			if(m[s[start]] > 0) ++count;
        			
        			if(i-start+1 < len) {
        	            len = i-start+1;
        	            head = start;
        	        }
        		}
        		start++;
        	}
        }
        return len==INT_MAX ? "" : s.substr(head, len);
    }
};

//concise and fast one
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        int len = INT_MAX, start = 0, head = 0, count = t.size();
        for(char c : t) 
        	m[c]++;
        for(int i = 0; i < s.size(); ++i) {
            if(m[s[i]]-- > 0) count--;
            while(count == 0) {
                if(len > i-start+1) {
                   len = i-start+1;
                   head = start;
                }
                if(m[s[start++]]++ == 0) count++;
            }
        }
        return len==INT_MAX ? "" : s.substr(head, len);
    }
};
