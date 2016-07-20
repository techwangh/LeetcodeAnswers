//这个竟然AC了，思路都不知道跑哪里去了。其中binarySearch可以由recurSearch代替
//等于号的处理很麻烦
class Solution {
public:
    int search(vector<int>& nums, int target) {
    	return recurSearch(nums, 0, nums.size()-1, target);
    }
    int recurSearch(vector<int>& nums, int left, int right, int target) {
    	if(left == right) 
    		return nums[left] == target ? left : -1;
    	if(left > right) return -1;
        int mid = (left + right) / 2;
    	if(nums[left] <= nums[mid]) {	//必须有“=”，处理两个值的情况
    		if(target >= nums[left] && target <= nums[mid]) {
    			return binarySearch(nums, left, mid, target);
    		} else {
    			return recurSearch(nums, mid+1, right, target);
    		}
    	} else {
    		if(target > nums[mid] && target <= nums[right]) {
    			return binarySearch(nums, mid+1, right, target);
    		} else {
    			return recurSearch(nums, left, mid, target);
    		}
    	}
    }
    int binarySearch(vector<int>& nums, int left, int right, int target) {
    	if(left > right) return -1;
    	int mid = (left + right) / 2;
    	if(target == nums[mid]) 
    		return mid;
    	else if(target < nums[mid])
    		return binarySearch(nums, left, mid-1, target);
    	else
    		return binarySearch(nums, mid+1, right, target);
    }
};

//more concise one, iteration
class Solution {
public:
    int search(vector<int>& nums, int target) {
  		int left = 0, right = nums.size()-1;
  		while(left <= right) {
  			int mid = (left + right) / 2;
  			if(target == nums[mid]) 
  				return mid;
  			else if(nums[left] <= nums[mid]) {		//[left, mid]有序,必须有“=”，处理两个值的情况
  				if(target >= nums[left] && target < nums[mid]) 
  					right = mid - 1;
  				else
  					left = mid + 1;		//上面已经判断过target == nums[mid]了
  			} else {
  				if(target > nums[mid] && target <= nums[right]) 
  					left = mid + 1;
  				else
  					right = mid - 1;
  			}
  		}
  		return -1;
    }
};