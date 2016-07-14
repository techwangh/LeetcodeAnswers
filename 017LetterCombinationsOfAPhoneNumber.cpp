class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if(digits.size() == 0) return res;
        string out = "";
        letterCombinationsDFS(res, out, dict, 0, digits);
        return res;
    }

    void letterCombinationsDFS(vector<string>& res, string& out, vector<string>& dict, int level, string& digits) {
    	if(level == digits.size()) {
    		res.push_back(out);
    		return;
    	}
    	string letters = dict[digits[level] - '2'];
    	for(char letter : letters) {
    		out.push_back(letter);
    		letterCombinationsDFS(res, out, dict, level+1, digits);
    		out.resize(level);
    	}
    }
};