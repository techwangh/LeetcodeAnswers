class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2, 0);
        int a = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        a &= -a;    //get the last '1' of a
        for(auto num : nums) {
            if(num & a) res[0] ^= num;
            else res[1] ^= num;
        }
        return res;
    }
};