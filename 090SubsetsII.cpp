class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> out;
        for(int i = 0; i <= nums.size(); ++i) {
        	combineDFS(nums, res, out, 0, i);
        }
        return res;

    }
    void combineDFS(vector<int>& nums, vector<vector<int>>& res, vector<int>& out, int start, int k) {
		if(out.size() == k) {
			res.push_back(out);
			return;
		}
		int end = nums.size()-(k-out.size())+1;
		for(int i = start; i < end; ++i) {
			out.push_back(nums[i]);
			combineDFS(nums, res, out, i+1, k);
			out.pop_back();
			while(nums[i] == nums[i+1]) ++i;
		}
    }
};