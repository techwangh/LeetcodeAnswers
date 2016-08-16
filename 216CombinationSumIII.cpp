class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> out;
        dfs(res, out, k, n, 1);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int> out, int k, int n, int start) {
    	if(k == 0 && n == 0) {
	    	res.push_back(out);
	    	return;
    	}
    	for(int i = start; i < 10; ++i) {
    	    if(n < i) return;
    		out.push_back(i);
    		dfs(res, out, k-1, n-i, i+1);
    		out.pop_back();
    	}
    }
};