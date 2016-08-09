class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto num : nums) {
            res ^= num;
        }
        return res;
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};

//use stl functions
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};