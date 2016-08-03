class Solution {
public:
    const int base = 1337;
    
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int digit = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, digit) % base;
    }

    int powmod(int a, int b) {
    	int res = 1;
    	a %= base;
    	while(b--) {
    		res = (res*a) % base;
    	}
    	return res;
    }
};

class Solution {
public:
    const int base = 1337;
    
    int superPow(int a, vector<int>& b) {
    	int res = 1;
    	for(int i = 0; i < b.size(); ++i) {
    		res = (pow(res, 10) * pow(a, b[i])) % base;
    	}
    	return res;
    }

    int pow(int a, int b) {
    	if(b == 0) return 1;
    	if(b == 1) return a % base;
    	return pow(a, b/2) * pow(a, b-b/2) % base;
    }

};