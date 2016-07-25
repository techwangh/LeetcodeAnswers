class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i) {
        	for(int j = 0; j < n; ++j) {
        		if(i == 0 || i == n-1 || j == 0 || j == m-1) {
        			solveDFS(board, i, j);
        		}
        	}
        }
        for(int i = 0; i < m; ++i) {
        	for(int j = 0; j < n; ++j) {
        		if(board[i][j] == 'O')
        			board[i][j] = 'X';
        		if(board[i][j] == '$')
        			board[i][j] = 'O';
        	}
        }
    }

    void solveDFS(vector<vector<char>>& board, int i, int j) {
    	if(board[i][j] == 'O') {
    		board[i][j] = '$';
    		if(i > 0) solveDFS(board, i-1, j);
    		if(j > 0) solveDFS(board, i, j-1);
    		if(i < board.size()-1) solveDFS(board, i+1, j);
    		if(j < board[0].size()-1) solveDFS(board, i, j+1);
    	}
    }
};