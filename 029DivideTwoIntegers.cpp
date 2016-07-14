//TLE
class Solution {
public:
    int divide(int dividend, int divisor) {
    	long long k = 0;
    	long long tmpDividend = abs((long long)dividend);
    	long long tmpDivisor = abs((long long)divisor);
        while(tmpDividend >= tmpDivisor) {
        	tmpDividend -= tmpDivisor;
        	++k;
        }
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
        	return -k;
        else
        	return k > INT_MAX ? INT_MAX : k;
    }
};


//取绝对值的时候，使用labs()在OJ上是AC，但用测试用例divide(1, INT_MIN)，程序会陷入死循环
//abs(), labs(), llabs()区别见笔记
class Solution {
public:
    int divide(int dividend, int divisor) {
  		if(!divisor || dividend == INT_MIN && divisor == -1) 
  			return INT_MAX;
  		long long tmpDividend = labs(dividend);		//这里使用labs在OJ上通过，但是使用abs就TLE，abs有三个重载版本啊，奇怪
    	long long tmpDivisor = labs(divisor);
    	int res = 0;
    	char sign = (dividend > 0 ^ divisor > 0) ? '-' : '+';
    	while(tmpDividend >= tmpDivisor) {
    		long long k = tmpDivisor, mutiple = 1;
    		while(tmpDividend >= (k << 1)) {
    			k <<= 1;
    			mutiple <<= 1;
    		}
			tmpDividend -= k;
			res += mutiple;
    	}
    	return sign == '+' ? res : -res;
    }
};