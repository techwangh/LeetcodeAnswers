class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuDFS(board, 0, 0);
    }

    bool solveSudokuDFS(vector<vector<char>>& board, int i, int j) {
    	if(i == 9) return true;
    	if(j == 9) return solveSudokuDFS(board, i+1, 0);
    	if(board[i][j] == '.') {
    		set<char> nums = getNums;
    		for(int k = 1; k <= 9; ++k) {
    			char c = '0' + k;
    			if(!nums.count(c)) {
    				board[i][j] = c;
    				if(isValid(board, i, j) && solveSudokuDFS(board, i, j+1)) 
    					return true;
    				board[i][j] = '.';
    			}
    		}
    	} else {
    		return solveSudokuDFS(board, i, j+1);
    	}
    }

    set<char> getNums(vector<vector<char>>& board, int row, int col) {
    	set<char> nums;
    	for(int i = 0; i < 9; ++i) {
    		nums.insert(board[row][i]);
    		nums.insert(board[i][col]);
    	}
    	for(int i = row/3*3; i < row/3*3+3; ++i) {
    		for(int j = col/3*3; j < col/3*3+3; ++j) {
    			nums.insert(board[i][j]);
    		}
    	}
    	return nums;
    }

    bool isValid(vector<vector<char>>& board, int row, int col) {
    	for(int i = 0; i < 9; ++i) {
    		if(i != row && board[i][col] == board[row][col])
    			return false;
    		if(i != col && board[row][i] == board[row][col]) 
    			return false;
    	}
    	for(int i = row/3*3; i < row/3*3+3; ++i) {
    		for(int j = col/3*3; j < col/3*3+3; ++j) {
    			if((i != row || j != col) && board[i][j] == board[row][col])
    				return false;
    		}
    	}
    	return true;
    }
};