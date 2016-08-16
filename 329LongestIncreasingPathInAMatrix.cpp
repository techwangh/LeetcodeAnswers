class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    	if(matrix.empty() || matrix[0].empty()) return 0;
        int res = 0;
        vector<vector<int>> maxLength(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); ++i) {
        	for(int j = 0; j < matrix[0].size(); ++j) {
        		dfs(matrix, maxLength, res, 0, i, j);
        	}
        }
        return res;
    }

    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& maxLength, int& res, int curLength, int i, int j) {
    	curLength++;
    	if(curLength <= maxLength[i][j]) return;
    	else maxLength[i][j] = curLength;
    	res = max(res, curLength);
    	if(i-1 >= 0 && matrix[i-1][j] > matrix[i][j]) dfs(matrix, res, curLength, i-1, j);
    	if(j-1 >= 0 && matrix[i][j-1] > matrix[i][j]) dfs(matrix, res, curLength, i, j-1);
    	if(i+1 < matrix.size() && matrix[i+1][j] > matrix[i][j]) dfs(matrix, res, curLength, i+1, j);
    	if(j+1 < matrix[0].size() && matrix[i][j+1] > matrix[i][j]) dfs(matrix, res, curLength, i, j+1);
    }
};

//faster
class Solution {
public:
	int m, n;
	vector<vector<int>> maxLength;		//maxLength from point(i, j)
	
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    	if(matrix.empty() || matrix[0].empty()) return 0;
        int res = 0;
        m = matrix.size();
        n = matrix[0].size();
        maxLength.resize(m , vector<int>(n, 0));
        for(int i = 0; i < matrix.size(); ++i) {
        	for(int j = 0; j < matrix[0].size(); ++j) {
        		res = max(res, dfs(matrix, INT_MIN, i, j));
        	}
        }
        return res;
    }

    int dfs(vector<vector<int>>& matrix, int cur, int i, int j) {
    	if(i < 0 || j < 0 || i >= m || j >= n || matrix[i][j] <= cur) 
    		return 0;
    	if(maxLength[i][j] > 0) 
    		return maxLength[i][j];

    	int a = dfs(matrix, matrix[i][j], i-1, j);
    	int b = dfs(matrix, matrix[i][j], i+1, j);
    	int c = dfs(matrix, matrix[i][j], i, j-1);
    	int d = dfs(matrix, matrix[i][j], i, j+1);

    	maxLength[i][j] = max(a, max(b, max(c, d))) + 1;
    	return maxLength[i][j];
    }
};