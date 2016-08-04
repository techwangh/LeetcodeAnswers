class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n/5 + trailingZeroes(n/5);
    }
};