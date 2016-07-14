class Solution {
public:
    bool isValid(string s) {
        map<char, char> parentheses = {{')', '('}, 
        							   {']', '['},
        							   {'}', '{'}};
        stack<char> s;
        for(char letter : s) {
        	if(letter == '(' || letter == '[' || letter == '{') 
        		s.push(letter);
        	else {
        		if(!s.empty() && s.top() == parentheses[letter]) 
        			s.pop();
        		else
        			return false;
        	}
        }
        if(sta.empty()) return true;
        else return false;
    }
};