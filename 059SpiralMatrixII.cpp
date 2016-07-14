//same as spiral matrix I
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
  		vector<vector<int>> res(n, vector<int>(n, 0));
  		int num = 1;
  		for(int k = 0; k < n/2; ++k) {
  			int i,j;
  			for(j = k; j < n-k; ++j)
  				res[k][j] = num++;
  			for(i = k+1; i < n-1-k; ++i)
  				res[i][n-1-k] = num++;
  			if(n-1-k != k) {
  				for(j = n-1-k; j >= k; --j) 
  					res[n-1-k][j] = num++;
  				for(i = n-2-k; i > k; --i)
  					res[i][k] = num++;
  			}
  		}      	
    }
    return res;
};