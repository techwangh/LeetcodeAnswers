class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for(int i = 0; i < nums.size(); ++i) {
        	if(i+1 < nums.size() && nums[i] == nums[i+1]) {
        		nums[k++] = nums[i];
        		nums[k++] = nums[i+1];
        		while(nums[i] == nums[i+1]) ++i;
        	}
        	else {
        		nums[k++] = nums[i];
        	}
        }
        return k;
    }
};