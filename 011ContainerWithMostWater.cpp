//这题和求柱形图最大面积那题的区别在哪里

class Solution {
public:
    int maxArea(vector<int>& height) {
    	int left = 0, right = height.size()-1;
  		int res = 0;
  		while(left < right) {
  			res = max(res, (right-left) * min(height[left], height[right]));
  			if(height[left] < height[right])
  				left++;
  			else
  				right--;
  		}  	
  		return res;
    }
};

//faster one
class Solution {
public:
    int maxArea(vector<int>& height) {
    	int left = 0, right = height.size()-1;
  		int res = 0;
  		while(left < right) {
  			res = max(res, (right-left) * min(height[left], height[right]));
  			if(height[left] < height[right]) {
  				int leftVal = height[left];
  				left++;
				while(height[left] <= leftVal)
					left++;  				
  			}
  			else {
  				int rightVal = height[right];
  				right--;
				while(height[right] <= rightVal)
					right--;
  			}
  		}
  		return res;
	}
};