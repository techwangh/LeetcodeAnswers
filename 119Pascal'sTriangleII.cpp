class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        for(int i = 1; i <= rowIndex; ++i) {
        	vector<int> tmp(i+1, 0);
        	tmp[0] = tmp[i] = 1;
        	for(int j = 1; j < i; ++j) {
        		tmp[j] = res[j-1] + res[j];
        	}
        	res = tmp;
        }
        return res;
    }
};

//只用n个存储空间，上面的解法用了2n个存储空间
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 0);
        res[0] = 1;
        for(int i = 1; i <= rowIndex; ++i) {
        	for(int j = i; j >= 1; --j) {
        		res[j] += res[j-1];
        	}
        }
  		return res;
    }
};