class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
        	int index = nums[i] - 1;
        	if(index != i && nums[i] > 0 && nums[i] <= nums.size())
        		if(nums[i] != nums[index]) {
        			swap(nums[i], nums[index]);
        			--i;	//防止i后面的值被换到前面，导致被换的那个数没有被处理。
        		}
        		
        }
        for(int i = 0; i < nums.size(); ++i) {
        	if(nums[i] != i+1)
        		return i+1;
        }
        return nums.size()+1;
    }
};