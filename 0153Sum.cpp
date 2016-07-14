class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    	vector<vector<int>> res;
    	int left = 0, right = 0, sum = 0;
    	for(int i = 0; i < int(nums.size()-2); ++i) {
    		if(i == 0 || nums[i] != nums[i-1]) {
    			left = i + 1;
    			right = nums.size() - 1;
    			sum = -nums[i];
    			while(left < right) {
    				if(nums[left] + nums[right] == sum) {
    					res.push_back({nums[left], nums[right], -sum});
    					while(left < right && nums[left] == nums[left+1]) ++left;
    					while(left < right && nums[right] == nums[right-1]) --right;
    					++left;
    					--right;
    				}
    				else if(nums[left] + nums[right] < sum) 
    					++left;
    				else
    					--right;
    			}
    		}
    	}
    	return res;
    }
};