class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if(num.empty()) return res;
        dfs(res, "", num, target, 0, 0, 0);
        return res;
    }

    void dfs(vector<string>& res, string path, string num, int target, int pos, long sum, long prev) {
    	if(pos == num.size()) {
    		if(sum == target) res.push_back(path);
    		return;
    	}
    	for(int i = pos+1; i <= num.size(); ++i) {
    		if(num[pos] == '0' && i > pos+1) break;
    		string str = num.substr(pos, i-pos);
    		long val = stol(str);
    		if(pos == 0) {
    			dfs(res, path+str, num, target, i, sum+val, val);
    		}
    		else {
    			dfs(res, path+"+"+str, num, target, i, sum+val, val);
    			dfs(res, path+"-"+str, num, target, i, sum-val, -val);
    			dfs(res, path+"*"+str, num, target, i, sum-prev + prev*val, prev*val); 
    		}
    	}
    }
};