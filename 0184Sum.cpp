//select one num first, and select 3 more nums in the rest nums, it turn into 3Sum questions
//one more loop than 3Sum, O(n^3)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	sort(nums.begin(), nums.end());
    	int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < int(n-3); ++i) {
        	if(i != 0 && nums[i] == nums[i-1]) continue;
        	if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
        	if(nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;
        	for(int j = i+1; j < int(n-2); ++j) {
        		if(j != i+1 && nums[j] == nums[j-1]) continue;
        		if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
        		int left = j + 1, right = n - 1;
        		while(left < right){
	        		int sum = nums[i] + nums[j] + nums[left] + nums[right];
	        		if(sum == target) {
	        			res.push_back({nums[i], nums[j], nums[left], nums[right]});
	        			while(left < right && nums[left] == nums[left+1]) ++left;
	        			while(left < right && nums[right] == nums[right-1]) --right;
	        			++left;
	        			--right;
	        		}
	        		else if(sum < target)
	        			++left;
	        		else
	        			--right;
        		}
        	}
        }
        return res;
    }
};