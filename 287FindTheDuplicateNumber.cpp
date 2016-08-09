//O(nlogn)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    	int left = 1, right = nums.size();
    	while(left < right) {
    		int mid = (left + right) / 2;, count = 0;
    		for(auto num : nums) {
    			if(num <= mid) ++count;
    		}
    		if(count > mid) right = mid;
    		else left = mid + 1;
    	}
    	return left;
    }
};

//O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
 		int slow = 0, fast = 0;
 		slow = nums[0]; 
 		fast = nums[nums[fast]];
 		while(slow != fast) {
 			slow = nums[slow];
 			fast = nums[nums[fast]];
 		}
 		fast = 0;
 		while(slow != fast) {
 			slow = nums[slow];
 			fast = nums[fast];
 		}
 		return slow;
    }
};