class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		generateParenthesisDFS(n, n, res, "");
		return res;
	}

	void generateParenthesisDFS(int left, int right, vector<string>& res, string out) {
		if(left > right) return;
		if(left == 0 && right == 0)
			res.push_back(out);
		else {
			if(left > 0) generateParenthesisDFS(left-1, right, res, out + '(');
			if(right > 0) generateParenthesisDFS(left, right-1, res, out + ')');
		}
	}
};


