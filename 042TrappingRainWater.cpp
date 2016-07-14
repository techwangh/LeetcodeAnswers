class Solution {
public:
    int trap(vector<int>& height) {
    	if(height.size() <= 2) return 0;
    	int res = 0, area = 0;
    	int left = 0, right = height.size()-1;

    	while(left < right) {
    		while(height[left+1] >= height[left]) ++left;
    		while(height[right-1] >= height[right]) --right;
    		if(height[left] <= height[right]){
    			int i = left+1;
    			while(i < right && height[i] < height[left])
    				++i;
    			area = computeArea(height, left, i, height[left]);
    			left = i;
    		}else {
    			int i = right-1;
    			while(i > left && height[i] < height[right])
    				--i;
    			area = computeArea(height, i, right, height[right]);
    			right = i;
    		}
    		res += area;
    	}
    	return res;
    }
    int computeArea(vector<int>& height, int left, int right, int h) {
        int fullArea = (right-left-1) * h;
    	int soilArea = 0;
    	left++;
    	while(left < right) { 
    		soilArea += height[left];
    		++left;
    	}
    	return fullArea - soilArea;
        
    }
};


//more concise one
class Solution {
public:
    int trap(vector<int>& height) {
  		int res = 0, left = 0, right = height.size()-1;
  		while(left < right) {
    		while(height[left+1] >= height[left]) ++left;
    		while(height[right-1] >= height[right]) --right;

    		int pivot = min(height[left], height[right]);
    		if(height[left] < height[right]) {
    			left++;
    			while(left < right && height[left] < pivot){
    				res += pivot - height[left];
    				++left;
    			}
    		} else {
    			right--;
    			while(left < right && height[right] < pivot) {
    				res += pivot - height[right];
    				--right;
    			}
    		}			
  		}
  		return res;
    }
};

//brilliant one
//reference:https://discuss.leetcode.com/topic/5125/sharing-my-simple-c-code-o-n-time-o-1-space
class Solution {
public:
    int trap(vector<int>& height) {
  		int left = 0, right = height.size()-1, res = 0;
  		int lefMax = 0, rightMax = 0;
  		while(left < right) {
  			if(height[left] <= height[right]) {
  				if(height[left] >= leftMax) 
  					leftMax = height[left];
  				else
  					res += leftMax - height[left];
  				++left;
  			} else {
  				if(height[right] >= rightMax)
  					rightMax = height[right];
  				else
  					res += rightMax - height[right];
  				--right;
  			}
  		}
  		return res;
    }
};

//DP,思路类似上面那个
class Solution {
public:
    int trap(vector<int>& height) {
    	int n = height.size();
		vector<int> dp(n, 0);	
		int res = 0, mx = 0;
		for(int i = 0; i < n; ++i) {
			dp[i] = mx;		//此处dp[i]表示i之前的所有值的最大值
			mx = max(mx, height[i]);
		}    
		mx = 0;
		for(int i = n-1; i >= 0; --i) {
			dp[i] = min(dp[i], mx);		//此处dp[i]表示i的左边和右边最大值中的较小值
			mx = max(mx, height[i]);
			if(dp[i] > height[i])
				res += dp[i] - height[i];
		}
		return res;
	}
};