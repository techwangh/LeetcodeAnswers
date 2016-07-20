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

//more concise one
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
  		int k = 0; 
  		for(int num :nums) {
  			if(k < 2 || num != nums[k-2])
  				nums[k++] = num;
  		}
  		return k;
    }
};