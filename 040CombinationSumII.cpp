class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> out;
        vector<vector<int>> res;
        combinationSum2DFS(candidates, target, 0, out, res);
        return res;
    }

    void combinationSum2DFS(vector<int>& candidates, int target, int left, vector<int>& out, vector<vector<int>>& res) {
    	if(target == 0) {
    		res.push_back(out);
    		return;
    	}
    	for(int i = left; i < candidates.size(); ++i) {
    		if(target >= candidates[i] && (i == left || candidates[i] != candidates[i-1])) {
    			out.push_back(candidates[i]);
    			combinationSum2DFS(candidates, target - candidates[i], i+1, out, res);
    			out.pop_back();
    		}
    	}

    }
};