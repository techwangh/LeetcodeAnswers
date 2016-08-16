class Solution {
public:
	int m, n;
    vector<vector<bool>> visited;

    int numIslands(vector<vector<char>>& grid) {
    	int res = 0;
        if(grid.empty() || grid[0].empty()) return 0;
        m = grid.size(); 
        n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));

        for(int i = 0; i < m; ++i) {
        	for(int j = 0; j < n; ++j) {
        		if(grid[i][j] == '1' && !visited[i][j]) res++;
        		dfs(grid, i, j);
        	}
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
    	if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || visited[i][j])
    		return;
    	visited[i][j] = true;
    	dfs(grid, i-1, j);
    	dfs(grid, i+1, j);
    	dfs(grid, i, j-1);
    	dfs(grid, i, j+1);
    }
};