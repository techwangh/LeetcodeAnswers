class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int signPos = -1;
        long long res = 0;
        while(str[i] == ' ' && i < str.size()) 
        	++i;
        if(i < str.size()) {
        	if(str[i] == '+' || str[i] == '-') {
        		return constructNum(str, i+1, str[i]);
        	}
        	else if(str[i] >= '0' && str[i] <= '9') {
        		return constructNum(str, i, '+');
        	}
        	else {
        		return 0;
        	}
        }
        return 0;
    }

    int constructNum(string str, int i, char sign) {
    	long long res = 0;
    	while(str[i] >= '0' && str[i] <= '9') {
        	res = res * 10 + str[i] - '0';
        	++i;
        	if(sign == '-' && -res < INT_MIN)
        		return INT_MIN;
        	else if(sign == '+' && res > INT_MAX) 
        		return INT_MAX;
        }
        return res;
    }
};