class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	if(nums.size() <= 1) return;
        int i = nums.size() - 2;
        while(nums[i] >= nums[i+1]) 
        	--i;
        if(i != -1) {
        	int index = findMinGreaterThanK(nums, i+1, nums.size()-1, nums[i]);
        	swap(nums[i], nums[index]);
        }
        int left = i+1, right = nums.size()-1;
        while(left < right) {
        	swap(nums[left++], nums[right--]);
        }
    }

    int findMinGreaterThanK(vector<int>& nums, int left, int right, int k) {
    	int minDiff = INT_MAX;
    	int index = right;
    	for(int i = right; i >= left; --i) {
    		if(nums[i] > k && minDiff > nums[i] - k) {
    			minDiff = nums[i] - k;
    			index = i;
    		}
    	}
    	return index;
    }
};