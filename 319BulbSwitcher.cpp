//TLE...
class Solution {
public:
    int bulbSwitch(int n) {
        int res = n;
        for(int i = 2; i <= n; ++i) {
        	if(isPrime(i)) {
        		res--;
        		prime.push_back(i);
        	}
        	else {
        		if(numOfDivisors(i) % 2 != 0) res--;
        	}
        }
        return res;
    }

    bool isPrime(int n) {
    	if(n >=1 && n <= 3) return true;
    	for(int i = 0; i < prime.size(); ++i) {
    		if(prime[i] * prime[i] > n) break;
    		if(n % prime[i] == 0) return false;
    	}
    	return true;
    }

    int numOfDivisors(int n) {	
    	int i = 0, res = 1, num = 0;
    	while(n != 1) {
    		if(n % prime[i] == 0) {
    			n /= prime[i];
    			num++;
    		}
    		else {
    		    if(num != 0) {
    		        res *= (num+1);
    		        num = 0;
    		    }
    		    i++;
    		}
    			
    	}
    	res *= (num+1);
    	return res-1;
    }
    
private:
    vector<int> prime;
};


//对于第i个位置，如果i是质数，则该位置灯是灭的，如果不是质数，则i可以表示为两个数的乘积，这两个数对i位置做了一次开和关，结果不变
//但是如果i是完全平方数，则有一次乘积是两个相同数相乘，只对该位置做一次动作，如36 = 6*6
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};