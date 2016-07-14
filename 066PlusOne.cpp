class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), carry = 0;
        digits[n-1]++;
        if(digits[n-1] == 10) {
            for(int i = n-1; i >= 0; --i) {
                digits[i] += carry;
                carry = digits[i] == 10 ? 1 : 0;
                if(carry == 0) break;
                digits[i] = 0;
            }
        }
        if(carry == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};