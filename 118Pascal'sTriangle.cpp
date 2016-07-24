class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0) return res;
        vector<int> out1{1};
        res.push_back(out1);
        for(int i = 1; i < numRows; ++i) {
        	vector<int> out2(i+1, 0);
        	out2[0] = 1; out2[i] = 1;
        	for(int j = 1; j < i; ++j) {
        		out2[j] = out1[j-1] + out1[j];
        	}
        	res.push_back(out2);
        	out1 = out2;
        }
        return res;
    }
};