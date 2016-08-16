class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()) return res;
        
        int left = nums[0], right = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] != nums[i-1] + 1) {
                res.push_back(constructRange(left, nums[i-1]));
                left = nums[i];
            }
        }
        res.push_back(constructRange(left, nums.back()));
        return res;
    }
    
    string constructRange(int left, int right) {
        string range;
        if(left == right) 
            range = to_string(left);
        else 
            range = to_string(left) + "->" + to_string(right);
        return range;
    }
};