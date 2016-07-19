//worst case is O(n)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;
        while(left <= right) {
        	mid = (left+right) / 2;
        	if(target == nums[mid]) return true;
        	else if(nums[mid] < nums[right]) {	//右边有序
        		if(nums[mid] < target && target <= nums[right])
        			left = mid+1;
        		else
        			right = mid-1;
        	}
        	else if(nums[mid] > nums[right]) {	//左边有序
        		if(nums[left] <= target && target < nums[mid])
        			right = mid-1;
        		else
        			left = mid+1;
        	}
        	else
        		right--;
        }
        return false;
    }
};