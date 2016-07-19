class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if(matrix.size() == 0 || matrix[0].size() == 0) return false;
    	int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m*n-1;
        while(start <= end) {
        	int mid = (start + end) / 2;
        	int midVal = matrix[(mid)/n][(mid)%n];
        	if(midVal == target) return true;
        	else if(midVal < target) 
        		start = mid+1;
        	else 
        		end = mid-1;
        }
        return false;
    }  
};