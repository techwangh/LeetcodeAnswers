//TLE
class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1;
        stack<int> stk;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] >= '0') {
                int num = getNum(s, i);
                stk.push(num * sign);
            }
            else if(s[i] == '-')
                sign = -1;
            else if(s[i] == '+')
                sign = 1;
            else if(s[i] == '*' || s[i] == '/') {
                char c = s[i];
                int num1 = stk.top();
                stk.pop();
                i++;
                while(i < s.size() && s[i] == ' ') ++i;
                int num2 = getNum(s, i);
                int num = c == '*' ? num1*num2 : num1/num2;
                stk.push(num);
            }
        }
        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
    
    int getNum(string s, int& i) {
        int num = s[i++] - '0';
        while(i < s.size() && s[i] >= '0') {
            num = num*10 + s[i]-'0';
            ++i;
        }
        --i;
        return num;
    }
};


class Solution {
public:
    int calculate(string s) {
        istringstream in('+' + s + '+');
        int num = 0, total = 0, n = 0;
        char op;
        while(in >> op) {
            if(op == '+' || op == '-') {
                total += num;
                in >> num;
                num *= op == '+' ? 1 : -1;
            }
            else {
                in >> n;
                if(op == '*')  num *= n;
                else num /= n;
            }
        }
        return total;
    }
};

ref:https://discuss.leetcode.com/topic/16807/17-lines-c-easy-20-ms