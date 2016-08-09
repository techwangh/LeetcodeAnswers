class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int twice = 0, ones = 0;
        for(auto num : nums) {
            twice |= (ones & num);
            ones ^= num;
            int tmp = twice & ones; //出现了3次的位上为1
            twice &= ~tmp;      //把出现了3次的位置零
            ones &= ~tmp;
        }
        return ones;
    }
};