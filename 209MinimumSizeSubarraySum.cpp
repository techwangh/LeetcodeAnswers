class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX, sum = 0;
        int left = 0,right = 0;
        for(int right = 0; right < nums.size(); ++right) {
        	sum += nums[right];
        	while(sum >= s) {
        		res = min(res, right - left + 1);
        		sum -= nums[left++];
        	}
        }
        return res == INT_MAX ? 0 : res;
    }
};