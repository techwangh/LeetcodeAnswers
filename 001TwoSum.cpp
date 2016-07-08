//O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i+1; j < nums.size(); ++j) {
                if(nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val_index;
        for(int i = 0; i < nums.size(); ++i) {
            int t = target - nums[i];
            if(val_index.count(t))
                return {i, val_index[t]};
            val_index[nums[i]] = i;
        }
        return {};
    }
};