class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
    	int n = x.size();
        for(int i = 0; i < n-3; ++i) {
        	if(x[i] >= x[i+2] && x[i+3] >= x[i+1])
        		return true;
        	if(i < n-4 && x[i+1] == x[i+3] && x[i+4] + x[i]>= x[i+2])
        		return true;
        	if(i < n-5 && x[i+2] > x[i+4] && x[i] + x[i+4] >= x[i+2] && x[i+3] > x[i+1] && x[i+1] + x[i+5] >= x[i+3])
        		return true;
        }
        return false;
    }
};