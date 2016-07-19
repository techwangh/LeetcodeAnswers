class Solution {
public:
    bool isNumber(string s) {
    	int i = 0; 
        while(s[i] == ' ') ++i;
        if(i == s.size()) return false;
        else if(s[i] == '-' || s[i] == '+') return isValid(s, i+1);
        else return isValid(s, i);
    }

    bool isValid(string s, int start) {
        if(start == s.size()) return false;
    	vector<int> dotIndex, eIndex, posiIndex,negIndex;
    	if(s[start] == '.') dotIndex.push_back(start);
    	else if(s[start] >= '0' && s[start] <= '9') {}
    	else return false;

    	int i = 0;
    	for(i = start+1; i < s.size(); ++i) {
    		if(s[i] == ' ') break;
    		else if(s[i] == '.') dotIndex.push_back(i);
    		else if(s[i] == 'e') eIndex.push_back(i);
    		else if(s[i] >= '0' && s[i] <= '9') continue;
    		else if(s[i] == '+' || s[i] == '-') posiIndex.push_back(i);
    		else return false;
    	}
    	if(dotIndex.size() > 1 || eIndex.size() > 1 || posiIndex.size() > 1) return false;
    	if(posiIndex.size() == 1) {
    	    if(eIndex.size() == 0 || posiIndex[0]-eIndex[0] != 1) return false;
    	}
    	if(dotIndex.size() == 1) {
    		if(eIndex.size() == 1 && ((dotIndex[0] > eIndex[0]) || dotIndex[0] == start && eIndex[0] == start+1)) return false;
    		if(dotIndex[0] == start && i == start+1) return false;
    	}
    	if(s[i-1] == 'e' || s[i-1] == '+' || s[i-1] == '-') return false;
    	if(i < s.size()) {
    		while(s[i] == ' ') ++i;
    		if(i != s.size()) return false;
    	}
    	return true;
    }
};