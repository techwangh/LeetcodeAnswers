class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
        permute(res, nums, n, k);
        return res;
    }

    void permute(string& res, vector<int>& nums, int n, int k) {
    	if(n == 1) {
    		res.push_back(nums[1] + '0');
    		return;
    	}
        int length = 1, tmpn = n;
        tmpn--;
        while(tmpn != 1) {
            length *= tmpn;
            tmpn--;
        }
		int digit = ceil(double(k)/length);
		res.push_back(nums[digit] + '0');
		nums.erase(nums.begin() + digit);
		permute(res, nums, n-1, k-(digit-1)*length);
    }
};


//more concise one
class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        string nums = "123456789";
  		vector<int> f(n, 1);
  		for(int i = 1; i < n; ++i)
  			f[i] = f[i-1] * i;
  		--k;							//important!
  		for(int i = n-1; i >= 0; --i) {
  			int index = k / f[i];
  			k %= f[i];
  			res.push_back(nums[index]);
  			nums.erase(index, 1);
  		}
  		return res;
    }
};