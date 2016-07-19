class Solution {
public:
    vector<int> grayCode(int n) {
    	vector<int> res{0};
        for(int k = 0; k < n; ++k) {
        	int inc = 1 << k;
        	for(int i = res.size()-1; i >= 0; --i) {
        		res.push_back(res[i]+inc);
        	}
        }
        return res;
    }
};