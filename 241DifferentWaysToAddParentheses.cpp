class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int> res;
        for(int i = 0; i < s.size(); ++i) {
        	if(s[i] < '0') {
        		vector<int> left =  diffWaysToCompute(s.substr(0, i));
        		vector<int> right = diffWaysToCompute(s.substr(i+1));
            	for(int j = 0; j < left.size(); ++j) {
            		for(int k = 0; k < right.size(); ++k) {
            			if(s[i] == '+') res.push_back(left[j] + right[k]);
            			else if(s[i] == '-') res.push_back(left[j] - right[k]);
            			else res.push_back(left[j] * right[k]);
            		}
            	}
        	}
        }
        if(res.empty()) 
        	res.push_back(stoi(s));
        return res;
    }
};