class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> out;
        vector<vector<int>> res;
        combinationSumDFS(candidates, target, 0, out, res);
        return res;
    }

    void combinationSumDFS(vector<int>& candidates, int target, int left, vector<int>& out, vector<vector<int>>& res) {
    	if(target == 0) {
    		res.push_back(out);
    		return;
    	}
    	int i = left;
    	while(target >= candidates[i]) {
    		out.push_back(candidates[i]);
    		combinationSumDFS(candidates, target - candidates[i], 0, out, res);
    		out.pop_back();
    		++i;
    	}
    }
};