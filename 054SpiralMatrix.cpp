class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int> res;
    	if(matrix.size() == 0 || matrix[0].size() == 0) return res;
        int m = matrix.size();
    	int n = matrix[0].size();
    	int end = (min(m, n)-1) / 2;
    	for(int k = 0; k <= end; ++k) {
    		int i, j;
    		for(j = k; j < n-k; ++j) 
    			res.push_back(matrix[k][j]);
    		for(i = k+1; i < m-1-k; ++i) 
    			res.push_back(matrix[i][n-1-k]);
    		if(m-1-k != k) {
	    		for(j = n-1-k; j >= k; --j) 
	    			res.push_back(matrix[m-1-k][j]);
    		}
    		if(k != n-1-k) {
    		    for(i = m-2-k; i > k; --i) 
    				res.push_back(matrix[i][k]);
    		}
    	}
    	return res;
    }
};