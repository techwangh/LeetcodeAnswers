//TLE
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // if(k >= nums.size()) k = nums.size()-1;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 1; j <= k; ++j) {
                if(i + j < nums.size() && abs(long(nums[i] - nums[i+j])) <= t) return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	set<int> window;
    	for(int i = 0; i < nums.size(); ++i) {
    		if(i > k) window.erase(nums[i-k-1]);
    		auto pos = window.lower_bound(nums[i] - t);
    		if(pos != window.end() && *pos - nums[i] <= t) return true;
    		window.insert(nums[i]);
    	}
    	return false;
	}
};


class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	    vector<pair<int, int>> a;
	    for(int i = 0; i < nums.size(); ++i) {
	        a.push_back(make_pair(nums[i], i));
	    }
	    sort(a.begin(), a.end(), [](const pair<int, int>& a, const pair<int, int>& b)->bool {return a.first < b.first;});
	    int left = 0, right = 0;
	    for(right = 1; right < nums.size(); ++right) {
	        while(long(a[right].first) - long(a[left].first) > t) ++left;
	        for(int i = left; i < right; ++i) {
	            if(abs(a[right].second - a[i].second) <= k) return true;
	        }
	    }
	    return false;
	}
};