//TLE
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        for(int i = 0; i < int(nums.size())-1; ++i) {
            for(int j = i+1; j < nums.size(); ++j) {
                if(nums[i] > nums[j]) res[i]++;
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t, res(nums.size(), 0);
        for(int i = nums.size()-1; i >= 0; --i) {
        	int left = 0, right = t.size();
        	while(left < right) {
        		int mid = (left + right) / 2;
        		if(nums[i] <= t[mid]) right = mid;
        		else left = mid + 1;
        	}
        	res[i] = right;
        	t.insert(t.begin() + right, nums[i]);
        }
        return res;
    }
};