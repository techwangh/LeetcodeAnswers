class Solution {
public:
    bool canJump(vector<int>& nums) {
    	if(nums.size() <= 1) return true;

    	vector<bool> dp(nums.size(), false);
    	dp[0] = nums[0] == '0' ? false : true;
    	for(int i = 1; i < nums.size(); ++i) {
    		int k = i-1;
    		while(k >= 0 && (!dp[k] || nums[i] < i-k)) --k;
    		if(k < 0) dp[i] = false;
    		else dp[i] = true;
    	}
    	return dp[nums.size()-1];
    }
};


//another solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
	  	std::vector<int> dp(nums.size(), 0);	//dp[i]:从前面的点到第i个点剩余的最多步数
	  	for(int i = 1; i < nums.size(); ++i) {
	  		dp[i] = max(dp[i-1], nums[i-1]) - 1;
	  		if(dp[i] < 0) return false;
	  	}
	  	return dp[nums.size()-1] >= 0;
    }
};

//空间复杂度为O(1)的DP
//another solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
   		int leftSteps = 0;
   		for(int i = 1; i < nums.size(); ++i) {
   			leftSteps = max(leftSteps, nums[i-1]) - 1;
   			if(leftSteps < 0) return false;
   		}
   		return leftSteps >= 0;
    }
};