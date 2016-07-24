class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left <= right) {
            while(left < s.size() && !isalnum(s[left])) left++;
            if(left == s.size()) break;
            while(!isalnum(s[right])) right--;
            if(toupper(s[left]) != toupper(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};