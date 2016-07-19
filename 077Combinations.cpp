class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out;
        combineDFS(res, out, 1, n, k);
        return res;
    }

    void combineDFS(vector<vector<int>>& res, vector<int>& out, int start, int n, int k) {
    	if(out.size() == k) {
    		res.push_back(out);
    		return;
    	}
    	int end = n-(k-out.size())+1;
    	for(int i = start; i <= end; ++i) {
    		out.push_back(i);
    		combineDFS(res, out, i+1, n, k);
    		out.pop_back();
    	}
    }
};

