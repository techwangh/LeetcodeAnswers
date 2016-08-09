class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n; ++i) {
            int left = 0, j = 0;
            for(j = 0; j < n; ++j) {
                int index = (i+j) % n;
                left += gas[index];
                left -= cost[index];
                if(left < 0) {
                    if(index > i) i = index;
                    break;
                }
            }
            if(j == n) return i;
        }
        return -1;
    }
};