class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        nums.insert(nums.begin(), nums.end()-k, nums.end());
        nums.resize(n);
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
 		reverse(nums.begin(), nums.end()-k);
 		reverse(nums.end()-k, nums.end());
 		reverse(nums.begin(), nums.end());
    }
};