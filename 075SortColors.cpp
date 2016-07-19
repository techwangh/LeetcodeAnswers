//counting sort, two-pass
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> counts(3, 0);
        for(auto num : nums) {
        	counts[num]++;
        }
        int k = 0;
        for(int i = 0; i < 3; ++i) {
        	while(counts[i] != 0){
        		nums[k++] = i;
        		counts[i]--;
        	}
        }
    }
};

//one-pass
class Solution {
public:
    void sortColors(vector<int>& nums) {
  		int i = 0, j = nums.size()-1, k = 0;
  		while(k <= j) {
  			if(nums[k] == 0){
  				swap(nums[k], nums[i]);
  				++i;
  			}
  			if(nums[k] == 2) {
  				swap(nums[k], nums[j]);
  				--j;
  				--k;
  			}
  			++k;
  		}	
    }
};