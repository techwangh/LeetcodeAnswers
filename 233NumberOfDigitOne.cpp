class Solution {
public:
    int countDigitOne(int n) {
    	int res = 0;
        for(long long m = 1; m <= n; m*=10) {
        	int a = n/m, b = n%m;
        	res += (a+8)/10 * m + (a%10 == 1 ? b+1 : 0);
        }
        return res;
    }
};

ref:
https://discuss.leetcode.com/topic/18054/4-lines-o-log-n-c-java-python
