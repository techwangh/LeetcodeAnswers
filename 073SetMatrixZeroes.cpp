class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    	if(matrix.size() == 0 || matrix[0].size() == 0) return;
        int m = matrix.size(), n = matrix[0].size();
        bool zeroRow = false, zeroCol = false;
        for(int i = 0; i < n; ++i) {
        	if(matrix[0][i] == 0) {
        		zeroRow = true;
        		break;
        	}
        }	
        for(int i = 0; i < m; ++i) {
        	if(matrix[i][0] == 0) {
        		zeroCol = true;
        		break;
        	}
        }
        for(int i = 1; i < m; ++i) {
        	for(int j = 1; j < n; ++j) {
        		if(matrix[i][j] == 0) {
        			matrix[i][0] = 0;
        			matrix[0][j] = 0;
        		}
        	}
        }
        for(int i = 1; i < m; ++i) {
        	for(int j = 1; j < n; ++j) {
        		if(matrix[i][0] == 0 || matrix[0][j] == 0) {
        			matrix[i][j] = 0;
        		}
        	}
        }
        if(zeroCol) {
        	for(int i = 0; i < m; ++i) 
        		matrix[i][0] = 0;
        }
        if(zeroRow) {
        	for(int i = 0; i < n; ++i) {
        		matrix[0][i] = 0;
        	}
        }

    }
};