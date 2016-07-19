class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return 1;
        long start = 0, end = 1e5;
        long mid = 0;
        while(start+1 < end) {
            mid = (start + end) / 2;
        	if(mid*mid == x) return mid;
        	else if(mid*mid < x) start = mid;
        	else end = mid;
        }
        return start;
    }
};


//牛顿法求方程根,这里的方程为f(x) = x^2 -n
//https://zh.wikipedia.org/wiki/%E7%89%9B%E9%A1%BF%E6%B3%95
class Solution {
public:
    int mySqrt(int n) {
  		int pre = 0, cur = 1;
  		while(pre != cur) {
  			pre = cur;
  			cur = (cur + n/cur) / 2;	//由牛顿法推出来的递推式,这样不行：cur = cur/2 + n/(2*cur);
  		}
  		return cur;
    }
};