class Solution {
public:
    string removeDuplicateLetters(string s) {
    	unordered_map<char, int> m;
    	stack<char> stk;
    	vector<bool> isVisited(26, false);
    	for(auto c : s)
    		m[c]++;
    	for(int i = 0; i < s.size(); m[s[i]]--, ++i) {
    		if(isVisited[s[i] - 'a']) continue;
    		while(!stk.empty() && stk.top() > s[i] && m[stk.top()] > 0) {
    		    isVisited[stk.top() - 'a'] = false;
    			stk.pop();
    		}
    		stk.push(s[i]);
    		isVisited[s[i] - 'a'] = true;
    	}
    	string res;
    	while(!stk.empty()) {
    		res.push_back(stk.top());
    		stk.pop();
    	}
    	reverse(res.begin(), res.end());
    	return res;
    }
};