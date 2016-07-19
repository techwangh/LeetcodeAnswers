class Solution {
public:
    string simplifyPath(string path) {
    	vector<string> singlePath;
    	string res;
    	int i = 0;
    	while(i < path.size()) {
    		while(i < path.size() && path[i] == '/') ++i;
    		if(i == path.size()) break;
    		int start = i;
    		while(i < path.size() && path[i] != '/') ++i;
    		int end = i-1;
    		string s = path.substr(start, end-start+1);
    		if(s == "..") {
    			if(singlePath.size() != 0)
    				singlePath.pop_back();
    		}
    		else if(s != ".") {
    			singlePath.push_back(s);
    		}
    	}
    	if(singlePath.size() == 0) return "/";
    	for(string s : singlePath) {
    	    res += "/";
    	    res += s;
    	}
    		
    	return res;
    }
};