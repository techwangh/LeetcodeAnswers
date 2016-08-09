class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> m;
        for(int i = 0; i < nums.size(); ++i) {
            m[nums[i]].push_back(i);
            if(m[nums[i]].size() > 1) {
                int n = m[nums[i]].size();
                if(m[nums[i]][n-1] - m[nums[i]][n-2] <= k) return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); ++i) {
            if(m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) return true;
            else m[nums[i]] = i;
        }
        return false;
    }
};