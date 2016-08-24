class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    	if(nums.size() <= 1) return nums.size();
        int res = 1;
        int i = 0, pre = 0;
        wile(i < nums.size()) {
        	while(i+1 < nums.size() && nums[i+1] >= nums[i]) ++i;
        	if(nums[i] != nums[pre]) {
        		res++;
        		pre = i;
        	}
        	if(i == nums.size()) break;
        	while(i+1 < nums.size() && nums[i+1] <= nums[i]) ++i;
        	res++;
        	pre = i;
        }
        return res;
    }
};

//more clear one
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    	if(nums.size() < 2) return nums.size();
    	int prevdiff = nums[1] - nums[0];
        int res = prevdiff == 0 ? 1 : 2;
        for(int i = 2; i < nums.size(); ++i) {
        	int diff = nums[i] - nums[i-1];
        	if(diff < 0 && prevdiff >= 0 || diff > 0 && prevdiff <= 0) {
        		res++;
        		prevdiff = diff;
        	}
        }
        return res;
    }
};