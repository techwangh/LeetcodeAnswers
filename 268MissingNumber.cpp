class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> exist(nums.size()+1, false);
        for(auto num : nums) {
        	exist[num] = true;
        }
        for(int i = 0; i < exist.size(); ++i) {
        	if(exist[i] == false)
        		return i;
        }
        return 0;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
  		int res = 0;
  		for(int i = 0; i < nums.size(); ++i) {
  			res ^= (i+1) ^ nums[i];
  		}
  		return res;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
  		int sum = 0;
  		int n = nums.size();
  		for(int i = 0; i < nums.size(); ++i) {
  			sum += nums[i];
  		}
  		return n*(n+1)/2 - sum;
  	}
};