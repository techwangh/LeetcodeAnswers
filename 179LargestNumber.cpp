class Solution {
public:
    string largestNumber(vector<int>& nums) {
    	if(nums.empty()) return "";
        string res;
        sort(nums.begin(), nums.end(), [] (int a, int b) {
        	return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        for(int i = 0; i < nums.size(); ++i) {
        	res += to_string(nums[i]);
        }
        return res[0] == '0' ? "0" : res;
    }
};


//faster
class Solution {
public:
    string largestNumber(vector<int>& nums) {
    	if(nums.empty()) return "";
        string res;
        vector<string> stringNums;
        for(auto num : nums) {
        	stringNums.push_back(to_string(num));
        }
        sort(stringNums.begin(), stringNums.end(), [] (string a, string b) { return a + b > b + a; });
        for(int i = 0; i < stringNums.size(); ++i) {
        	res += stringNums[i];
        }
        return res[0] == '0' ? "0" : res;
    }
};