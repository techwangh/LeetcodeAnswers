class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size() - 1;
        int res = 0;
        while(n >= 0 && s[n] == ' ') n--;
        if(n < 0) return 0;
        else {
            while(n >= 0 && s[n] != ' ') {
                --n;
                ++res;
            }
        }
        return res;
    }
};