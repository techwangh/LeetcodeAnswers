class Solution {
public:
    int calculate(string s) {
        int index = 0;
        return calc(s, index);
    }

    int calc(string s, int& index) {
    	vector<int> nums;
    	int res = 0;
    	int sign = 1;
    	while(index < s.size()) {
    		while(index < s.size() && s[index] == ' ') index++;		//skip spaces
    		if(index == s.size()) break;

    		if(s[index] == '(') {
    			index++;
    			int num = calc(s, index);
    			nums.push_back(sign*num);
    		}
    		else if(s[index] == ')') return sum(nums);
    		else if(s[index] == '+') sign = 1;
    		else if(s[index] == '-') sign = -1;
    		else {
    			int pos = s.find_first_not_of("0123456789", index);
    			int num = atoi(s.substr(index, pos - index).c_str());
    			nums.push_back(sign*num);
    			index = pos-1;
    		}
    	    index++;
    	}
    	return sum(nums);
    }

    int sum(vector<int>& vec) {
    	int res = 0;
    	for(auto num : vec) {
    		res += num;
    	}
    	return res;
    }
};


class Solution {
public:
    int calculate(string s) {
        int res = 0;
  		vector<int> sign(2, 1);
  		for(int i = 0; i < s.size(); ++i) {
  			char c = s[i];
  			if(c >= '0') {	//digits
  				int num = 0;
  				while(i < s.size() && s[i] >= '0') {
  					num = num*10 + s[i] - '0';
  					++i;
  				}
  				res += sign.back() * num;
  				sign.pop_back();
  				--i;
  			}
  			else if(c == ')') 
  				sign.pop_back();
  			else if(c != ' ') {
  				sign.push_back(sign.back() * (c == '-' ? -1 : 1));
  			}
  		}
  		return res;
    }
};