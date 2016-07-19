class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        int length = max(m, n);
        string res(length, '0');
        if(m < n) {
        	for(int i = 0; i < n-m; ++i) a.insert(a.begin(), '0');
        } 
    	else if(n < m) {
    		for(int i = 0; i < m-n; ++i) b.insert(b.begin(), '0');
    	}
    	int carry = 0;
    	for(int i = length-1; i >= 0; --i) {
    		int tmp = a[i]-'0' + b[i]-'0' + carry;
    		switch(tmp) {
    			case 0:
    				res[i] = '0';
    				carry = 0;
    				break;
    			case 1:
    				res[i] = '1';
    				carry = 0;
    				break;
    			case 2:
    				res[i] = '0';
    				carry = 1;
    				break;
    			case 3:
    				res[i] = '1';
    				carry = 1;
    				break;
    		}
    	}
    	if(carry) res.insert(res.begin(), '1');
    	return res;
    }
};