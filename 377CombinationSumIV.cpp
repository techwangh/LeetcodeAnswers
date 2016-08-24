class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0) return 1;
        if(target < 0) return 0;
        auto it = dp.find(target);
        if(it != dp.end()) return it->second;
        int res = 0;
        for(auto num : nums) {
        	res += combinationSum4(nums, target - num);
        }
        dp[target] = res;
        return res;
    }

private:
	unordered_map<int, int> dp;
};