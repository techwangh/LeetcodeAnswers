class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
    	int res;
    	int left = 0, right = 0;
    	long long diff = 0, minDiff = INT_MAX, sum = 0;
    	for(int i = 0; i < int(nums.size()-2); ++i) {
    		if(i == 0 || nums[i] != nums[i-1]) {
    			left = i + 1;
    			right = nums.size() - 1;
    			sum = target - nums[i];
    			while(left < right) {
    				diff = long long(nums[left] + nums[right] - sum);
    				if(minDiff < abs(diff)) {
    					minDiff = abs(diff);
    					res = target + diff;
    				}
    				if(diff == 0) {
    					return target;
    				}
    				else if(diff < 0) 
    					++left;
    				else
    					--right;
    			}
    		}
    	}
    	return res;
    }
};