class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
        	int mid = (left + right) / 2;
        	if(target == nums[mid]) {
        		int i = mid, j = mid;
        		while(i-1 >= 0 && nums[i-1] == target) --i;
        		while(j+1 < nums.size() && nums[j+1] == target) ++j;
        		return {i, j};
        	}
        	else if(target < nums[mid]) 
        		right = mid - 1;
        	else
        		left = mid + 1;
        }
        return {-1, -1};
    }
};