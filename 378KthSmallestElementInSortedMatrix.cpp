//still don't understand why the return value 'left' is a value in the matrix
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    	int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1];
        while(left < right) {
        	int mid = left + (right-left)/2;
        	int num = 0;
        	for(int i = 0; i < n; ++i) {
        		num += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        	}
        	if(num < k) left = mid+1;
        	else right = mid;
        }
        return left;
    }
};

ref:https://discuss.leetcode.com/topic/52865/my-solution-using-binary-search-in-c