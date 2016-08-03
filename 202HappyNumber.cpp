class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> nums;
        while(n != 1) {
            if(nums.find(n) != nums.end()) 
                return false;
            nums.insert(n);
            int tmp = 0;
            while(n != 0) {
                tmp += (n % 10) * (n % 10);
                n /= 10;
            }
            n = tmp;
        }
        return true;
    }
};