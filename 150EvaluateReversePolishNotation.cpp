class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto token : tokens) {
        	if(token.size() > 1 || token[0] >= '0')
        		s.push(stoi(token));
        	else {
        		int b = s.top();
        		s.pop();
        		int a = s.top();
        		s.pop();
        		int c = 0;
        		if(token == "+") c = a+b;
        		else if(token == "-") c = a-b;
        		else if(token == "*") c = a*b;
        		else c = a/b;
        		s.push(c);
        	}
        }
        return s.top();
    }
};