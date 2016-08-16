class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n) return m;
        int mask = 0x40000000, res = 0;
        while((mask & m) == (mask & n)) {
        	res |= (mask & m);
        	mask >>= 1;
        }
        return res;
    }
};