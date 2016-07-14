class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
    	int div = 1;
    	int tmpx = x;
    	tmpx /= 10;
        while(tmpx != 0) {
        	tmpx /= 10;
        	div *= 10;
        }
        while(div >= 10) {
            if(x%10 != x/div) return false;
            x = (x%div) / 10;
            div /= 100;
        }
        return true;
    }
};