class Solution {
public:
    bool isAdditiveNumber(string num) {
    	int mid = num.size() / 2, end = num.size() / 3 * 2;
        for(int l1 = 1; l1 <= mid; ++l1) {
        	for(int l2 = 1; l2 <= end-l1; ++l2) {
        		if(dfs(l1, l2, num, 0)) return true;
        	}
        }
        return false;
    }

    bool dfs(int l1, int l2, const string& num, int pos) {
    	int start = pos + l1 + l2;
    	if(start == num.size()) {
    		if(pos == 0) return false;
    		return true;
    	} 
    	int minLen = max(l1, l2);
    	if((num[pos] == '0' && l1 > 1) || (num[pos+l1] == '0' && l2 > 1)) return false;

    	long num1 = stol(num.substr(pos, l1)), num2 = stol(num.substr(pos+l1, l2));

    	for(int l = minLen; l <= num.size()-start; ++l) {
    		if(num[start] == '0' && l > 1) return false;

    		long sum = stol(num.substr(start, l));
    		if(sum == num1 + num2) {
    			if(dfs(l2, l, num, pos+l1)) return true;
    		}
    		else if(sum > num1 + num2) break;
    	}
    	return false;
    }
};


class Solution {
public:
    bool isAdditiveNumber(string num) {
    	int mid = num.size() / 2, end = num.size() / 3 * 2;
        for(int l1 = 1; l1 <= mid; ++l1) {
        	if(l1 > 1 && num[0] == 0) break;
        	long num1 = stol(num.substr(0, l1));
        	for(int l2 = 1; l2 <= end-l1; ++l2) {
        		if(l2 > 1 && num[l1] == 0) break;
        		long num2 = stol(num.substr(l1, l2));

        		int len = l1 + l2;
        		while(len < num.size()) {
        			long sum = num1 + num2;
        			string s_sum = to_string(sum);
        			string next = num.substr(len, s_sum.size());
        			if(next != s_sum) break;
        			else {
        				num1 = num2;
        				num2 = sum;
        				len += s_sum.size();
        			}
        		}
        		if(len == num.size()) return true;
        	}
        }
        return false;
    }
};