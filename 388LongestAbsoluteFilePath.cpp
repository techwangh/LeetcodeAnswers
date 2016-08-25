class Solution {
public:
    int lengthLongestPath(string input) {
    	int res = 0;
    	input = "\n" + input;
        vector<int> length(1000, 0);
        auto it = input.begin();
        while(it != input.end()) {
        	int level = 0;
    		while(*(++it) == '\t') level++;
    		auto it2 = find(it, input.end(), '\n');
    		string s = string(it, it2);
    		length[level] = s.size();
    		if(find(s.begin(), s.end(), '.') != s.end()) {
    			res = max(res, accumulate(length.begin(), length.begin()+level+1, 0)+level);
    		}
    		it = it2;
        }
        return res;
    }
};