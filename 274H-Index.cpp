class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
    	if(n == 0) return 0;
        sort(citations.begin(), citations.end());
        int left = 0, right = n-1;
        while(left <= right) {
        	int mid = (left + right) / 2;
        	if(citations[mid] >= n-mid) right = mid -1;
        	else left = mid + 1;
        }
        return n-right-1;
    }
};


class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); ++i) {
            if (i >= citations[i]) return i;
        }
        return citations.size();
    }
};