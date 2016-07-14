//这也能过。。
class Solution {
public:
    double myPow(double x, int n) {
        return pow(x, n);
    }
};

//TLE
class Solution {
public:
    double myPow(double x, int n) {
    	if(n == 0) return 1;
        double res = 1;
        int posiN = abs(n);
        while(posiN > 0) {
        	int k = 1;
        	double tmp = x;
        	while(2*k <= posiN) {
        		tmp *= tmp;
        		k <<= 1;
        	}
        	res *= tmp;
        	posiN -= k;
        }
        return n > 0 ? res : 1/res;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
    	if(n == 0) return 1;
  		if(n < 0) {
  			n = -n;
  			x = 1/x;
  		}
  		return n%2 == 0 ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
    }
};