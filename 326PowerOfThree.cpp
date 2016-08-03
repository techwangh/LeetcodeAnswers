class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n != 1 && n % 3 != 0) return false;
        int val = 1;
        while(val < n)
            val *= 3;
        return val == n;     
    }
};


class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1) return true;
        else if(n % 3 != 0) return false;
        long val = 3;
        while(n > 3) {
        	while(val*val < n)
        		val *= val;
        	if(n % val != 0) return false;
        	n /= val;
        	val = 3;
        }
        if(n == 3) return true;
        else return false;
    }
};