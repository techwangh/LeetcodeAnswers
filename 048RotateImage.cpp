class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int size = (n+1)/2;
        for(int i = 0; i < size; ++i) {
        	for(int j = 0; j < size; ++j) {
        		int val = matrix[i][j];
        		matrix[i][j] = matrix[n-1-j][i];
        		matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
        		matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
        		matrix[j][n-1-i] = val;
        	}
        }
    }
};