//really hard to understand, one of the most difficult problems
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
    	vector<int> res;
    	auto mid = nums.begin() + n/2;
        nth_element(nums.begin(), nums.begin()+mid, nums.end());
        int median = *mid;

        #define A(i) nums[(1+i*2) % (n|1)]

        int left = 0, right = nums.size()-1, i = 0;
        while(i <= right) {
        	if(A(i) > median) 
        		swap(A(i++), A(left++));
        	else if(A(i) < median)
        		swap(A(i), A(right--));
        	else 
        		i++;
        }
    }
};

ref:https://discuss.leetcode.com/topic/32929/o-n-o-1-after-median-virtual-indexing