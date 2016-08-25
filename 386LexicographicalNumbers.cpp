//TLE
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        auto lessThan = [] (int a, int b) { return to_string(a) < to_string(b); };
        vector<int> res;
        for(int i = 1; i <= n; ++i) {
            res.push_back(i);
        }
        sort(begin(res), end(res), lessThan);
        return res;
    }
};


class Solution {
public:
    vector<int> lexicalOrder(int n) {
    	vector<int> res;
    	res.push_back(1);
    	for(int i = 1; i < n; ++i) {
    		int pre = res[i-1];
    		if(pre*10 < n) res.push_back(pre*10);
    		else {
    			while(pre%10 == 9 || pre == n) pre /=10;
    			res.push_back(pre+1);
    		}
    	}
    	return res;
    }
};