class Solution {
public:
    bool isPerfectSquare(int num) {
        long begin = 1, end = num < 1e5 ? num : 1e5;
        long mid;
        while(begin <= end) {
        	mid = (begin + end) / 2;
        	long sqrt = mid * mid;
        	if(sqrt == num) return true;
        	else if(sqrt < num) begin = mid + 1;
        	else end = mid - 1;
        }
        return false;
    }
};