class Solution {
public:
    int maximumGap(vector<int>& nums) {
    	if(nums.size() < 2) return 0;
        int minVal = INT_MAX, maxVal = INT_MIN, n = nums.size();
        for(auto num : nums) {
        	minVal = min(minVal, num);
        	maxVal = max(maxVal, num);
        } 
        int avgGap = (maxVal-minVal) / (n-1) + 1;
        int bucketNums = (maxVal-minVal) / avgGap + 1;
        vector<int> mins(bucketNums, INT_MAX), maxs(bucketNums, INT_MIN);
        for(auto num : nums) {
        	int index = (num - minVal) / avgGap;
        	mins[index] = min(mins[index], num);
        	maxs[index] = max(maxs[index], num);
        }
        int pre = maxs[0];
        int res = maxs[0] - mins[0];
        for(int i = 1; i < bucketNums; ++i) {
            if(maxs[i] == INT_MIN) continue;
        	res = max(res, mins[i] - pre);
        	pre = maxs[i];
        }
        return res;
    }
};