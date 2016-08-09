class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right) {
        	if(nums[left] < nums[right]) return nums[left];
        	int mid = (left + right) / 2;
        	if(nums[mid] == nums[right]) {
        	    int i = mid + 1;
        	    while(i <= right && nums[i] == nums[mid]) ++i;
        	    if(i > right) right = mid;
        	    else left = mid + 1;
        	}
        	else if(nums[mid] < nums[right]) right = mid;
        	else left = mid + 1;
        }
        return nums[left];
    }
};