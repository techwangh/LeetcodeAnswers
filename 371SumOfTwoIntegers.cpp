//iteration
class Solution {
public:
    int getSum(int a, int b) {
        int tmpa;
        while(b != 0) {
            tmpa = a;
            a = a ^ b;
            b = (tmpa & b) << 1;
        }
        return a;
    }
};

//recursion
class Solution {
public:
    int getSum(int a, int b) {
    	return b == 0 ? a : getSum(a^b, (a&b) << 1);
    }
}
