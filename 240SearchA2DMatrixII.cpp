class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        if(target < matrix[0][0] || target > matrix.back().back()) return false;
        int i = matrix.size(), j = 0;
        while(true) {
        	if(target < matrix[i][j]) i--;
        	else if(target > matrix[i][j]) j++;
        	else return true;
        	if(i < 0 || j > matrix[0].size()) break;
        }
        return false;
    }
};