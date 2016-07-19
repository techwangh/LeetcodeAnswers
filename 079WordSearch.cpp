class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	if(word.size() == 0) return true;
    	if(board.size() == 0 || board[0].size() == 0) return false;
    	vector<vector<bool>> isUsed(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); ++i) {
        	for(int j = 0; j < board[0].size(); ++j) {
        		if(isValid(board, word, isUsed, i, j, 0)) 
        			return true;
        	}
        }
        return false;
    }

    bool isValid(vector<vector<char>>& board, string& word, vector<vector<bool>>& isUsed, int i, int j, int index) {
        if(index == word.size()) return true;
    	if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || isUsed[i][j] || word[index]!=board[i][j])
    		return false;
    	isUsed[i][j] = true;
    	bool res =  isValid(board, word, isUsed, i, j-1, index+1) ||
    				isValid(board, word, isUsed, i, j+1, index+1) ||
    				isValid(board, word, isUsed, i-1, j, index+1) ||
    				isValid(board, word, isUsed, i+1, j, index+1);
        isUsed[i][j] = false;
    	return res;
    }
};