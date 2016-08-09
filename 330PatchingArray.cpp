class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long res = 0, miss = 1, i = 0;
        while(miss <= n) {
        	if(i < nums.size() && nums[i] <= miss) {
        		miss += nums[i++];
        	}
        	else {
        		miss += miss;
        		res++;
        	}
        }
        return res;
    }
};

ref:https://discuss.leetcode.com/topic/35494/solution-explanation