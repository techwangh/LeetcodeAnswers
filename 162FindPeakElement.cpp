class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i+1 < n && nums[i] < nums[i+1]) ++i;
        return i;
    }
};


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
  		int low = 0, high = nums.size()-1;
  		while(low < high) {
  			int mid1 = (low + high) / 2;
  			int mid2 = mid1 + 1;
  			if(nums[mid1] > nums[mid2]) high = mid1;
  			else low = mid2;
  		}
  		return low;
    }
};