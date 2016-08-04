class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    	long lnumrator = long(numerator);
    	long ldenominator = long(denominator);
        vector<int> remainders;
        vector<long> resVec;
        char sign = lnumrator * ldenominator >= 0 ? '+' : '-';
        lnumrator = abs(lnumrator);
        ldenominator = abs(ldenominator);
        resVec.push_back(long(lnumrator) / long(ldenominator));
        lnumrator %= ldenominator;
        while(find(remainders.begin(), remainders.end(), lnumrator) == remainders.end()) {
        	if(lnumrator == 0) break;
        	
        	remainders.push_back(lnumrator);
        	lnumrator *= 10;
        	resVec.push_back(lnumrator / ldenominator);
        	lnumrator %= ldenominator;
        }
        string res;
       	if(resVec.size() > 1) {
        	res.push_back('.');
    		for(int i = 1; i < resVec.size(); ++i) {
    			res.push_back(resVec[i] + '0');
    		}
        	if(lnumrator != 0) {
        		int pos = find(remainders.begin(), remainders.end(), lnumrator) - remainders.begin();
        		res.insert(res.begin()+pos+1, '(');
        		res.push_back(')');
        	}
        }
        res = (sign == '-' ? "-" : "") + to_string(resVec[0]) + res;
        return res;
    }
};