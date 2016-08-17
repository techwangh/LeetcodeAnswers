class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_map<string, int> visited;
        queue<string> q;
        q.push(s);
        ++visited[s];
        bool found = false;
        while (!q.empty()) {
            s = q.front(); q.pop();
            if (isValid(s)) {
                res.push_back(s);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != '(' && s[i] != ')') continue;
                string t = s.substr(0, i) + s.substr(i + 1);
                if (visited.find(t) == visited.end()) {
                    q.push(t);
                    ++visited[t];
                }
            }
        }
        return res;
    }
    bool isValid(string t) {
        int cnt = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == '(') ++cnt;
            if (t[i] == ')' && cnt-- == 0) return false;
        }
        return cnt == 0;
    }
};


class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int remove_left = 0, remove_right = 0;
        for(int i = 0; i < s.size(); ++i) {
        	if(s[i] == '(') ++remove_left;
        	else if(s[i] == ')') {
        		if(remove_left) remove_left--;
        		else remove_right++;
        	}
        }
        unordered_set<string> res;
        helper(0, 0, remove_left, remove_right, s, "", res);
        return vector<string>(res.begin(), res.end());

    }

    void helper(int pair, int index, int remove_left, int remove_right, const string& s, string solution, unordered_set<string>& res) {
    	if(index == s.size()) {
    		if(pair == 0 && remove_left == 0 && remove_right == 0) {
    			res.insert(solution);
    		}
    		return;
    	}
    	if(s[index] == '(') {
    		if(remove_left) helper(pair, index+1, remove_left-1, remove_right, s, solution, res);
    		helper(pair+1, index+1, remove_left, remove_right, s, solution+s[index], res);
    	}
    	else if(s[index] == ')') {
    		if(remove_right) helper(pair, index+1, remove_left, remove_right-1, s, solution, res);
    		if(pair > 0) helper(pair-1, index+1, remove_left, remove_right, s, solution+s[index], res); 
    	}
    	else
    		helper(pair, index+1, remove_left, remove_right, s, solution+s[index], res);
    }
};

ref:https://discuss.leetcode.com/topic/34996/recommend-for-beginners-clean-c-implementation-with-detailed-explaination