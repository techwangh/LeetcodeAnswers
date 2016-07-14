class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> v(m+n, 0);
        int k = m+n-2;
        for(int i = 0; i < m; ++i) {
        	for(int j = 0; j < n; ++j) {
        		v[k-i-j] += (num1[i] - '0') * (num2[j] - '0');
        	} 
        }
        int carry = 0;
        for(int i = 0; i < m+n; ++i) {
        	v[i] += carry;
        	carry = v[i]/10;
        	v[i] %= 10;
        }
        int maxSize = m+n-1;
        while(maxSize >= 0 && v[maxSize] == 0) --maxSize;
        if(maxSize < 0) return "0";
        string res = "";
        while(maxSize >= 0) res.push_back(v[maxSize--] + '0');
        return res;
    }

};