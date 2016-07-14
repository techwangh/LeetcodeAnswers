//TLE
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> rows, cols;
        solveNQueensDFS(res, rows, cols, n);
        return res;
    }

    void solveNQueensDFS(vector<vector<string>>& res, vector<int>& rows, vector<int>& cols, int n) {
    	if(rows.size() == n) {
    		std::vector<string> out(n, string(n, '.'));
    		for(int i = 0; i < n; ++i) {
    			out[rows[i]][cols[i]] = 'Q';
    		}
    		res.push_back(out);
    		return;
    	}
    	for(int i = rows.size()==0 ? 0 : rows.back(); i < n; ++i) {
    		for(int j = 0; j < n; ++j) {
    			if(isAble(rows, cols, i, j)) {
    				rows.push_back(i);
    				cols.push_back(j);
    				solveNQueensDFS(res, rows, cols, n);
    				cols.pop_back();
    				rows.pop_back();
    			}
    		}
    	}
    }

    bool isAble(vector<int>& rows, vector<int>& cols, int x, int y) {
    	for(int i = 0; i < rows.size(); ++i) {
    		if(x == rows[i] || y == cols[i]) return false;
    		if(abs(x-rows[i]) == abs(y-cols[i])) return false;
    	}
    	return true;
    }
};


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> pos;	//pos[i]表示第i行的列数
        solveNQueensDFS(res, pos, 0, n);
        return res;
    }

    void solveNQueensDFS(vector<vector<string>>& res, vector<int>& pos, int row, int n) {
    	if(pos.size() == n) {
    		vector<string> out(n, string(n, '.'));
    		for(int i = 0; i < n; ++i) {
    			out[i][pos[i]] = 'Q';
    		}
    		res.push_back(out);
    	}
    	for(int col = 0; col < n; ++col) {
    		if(isValid(pos, row, col)) {
    			pos.push_back(col);
    			solveNQueensDFS(res, pos, row+1, n);
    			pos.pop_back();
    		}
    	}
    }

    bool isValid(vector<int>& pos, int row, int col) {
    	for(int i = 0; i < pos.size(); ++i) {
    		if(pos[i] == col || abs(row-i) == abs(col-pos[i]))
    			return false;
    	}
    	return true;
    }
};