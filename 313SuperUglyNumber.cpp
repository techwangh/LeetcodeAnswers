//TLE
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        map<int, int> m;
        for(auto prime : primes) 
        	m[prime] = 0;
        vector<int> res(1, 1);
        while(res.size() < n) {
        	int minVal = INT_MAX;
        	int minKey = 0;
        	for(auto prime : primes) 
        		minVal = min(minVal, res[m[prime]] * prime);
        	for(auto prime : primes) {
        		if(minVal == res[m[prime]] * prime)
        			m[prime]++;
        	}
        	res.push_back(minVal);
        }
        return res.back();
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
    	vector<int> res(1, 1), indices(primes.size(), 0);
    	while(res.size() < n) {
    		int minVal = INT_MAX;
    		for(int i = 0; i < primes.size(); ++i) 
    			minVal = min(minVal, res[indices[i]] * primes[i]);
    		for(int i = 0; i < primes.size(); ++i) {
    			if(minval == res[indices[i]] * primes[i])
    				indices[i]++;
    		}
    		res.push_back(minVal);	
    	}
    	return res.back();
    }
};