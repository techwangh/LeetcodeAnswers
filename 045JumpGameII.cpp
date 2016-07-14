//TLE
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) return 0;

    	vector<bool> canReach(nums.size(), false);
    	vector<int> minSteps(nums.size(), INT_MAX);
    	canReach[0] = nums[0] == '0' ? false : true;
    	minSteps[0] = 0;
    	for(int i = 1; i < nums.size(); ++i) {
    		for(int k = i-1; k >= 0; --k) {
    			if(canReach[k] && nums[k]+k >= i){
    				canReach[i] = true;
    				minSteps[i] = min(minSteps[i], minSteps[k] + 1);
    			}
    		}
    	}
    	return minSteps[nums.size()-1];
    }
};

//batter solution
class Solution {
public:
    int jump(vector<int>& nums) {
    	int i = 0, cur = 0, pre = 0;	//cur表示当前能达到的最远距离，pre表示上一步能达到的最远距离
    	int res = 0;
    	while(cur < nums.size()-1) {
    		pre = cur;
    		while(i <= pre) {
    			cur = max(cur, nums[i]+i);
    			++i;
    		}
    		++res;
    		if(pre == cur) return -1;	//前一个的最大距离和当前的最大距离相等，说明无法向前进了，无法到达最后一个位置。
    	}
    	return res;
    }
};

//上面一个算法的另一种写法
class Solution {
public:
    int jump(vector<int>& nums) {
  		int i = 0, pre = 0, cur = 0;
  		int res = 0;
  		for(int i = 0; i < nums.size(); ++i) {
  			if(i > pre) {
  				pre = cur;
  				++res;
  				if(cur >= nums.size()-1) return res;
  			}
  			cur = max(cur, nums[i] + i);
  		}
  		return res;
    }
};