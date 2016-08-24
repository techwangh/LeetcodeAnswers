class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        if(k == 0 || nums1.empty() || nums2.empty()) return res;
        auto cmp = [] (const pair<int, int>& a, const pair<int, int>& b) {return a.first + a.second > b.first + b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        for(auto n1 : nums1) {
        	for(auto n2 : nums2) {
        		minHeap.emplace(n1, n2);
        	}
        }
        while(k-- && !minHeap.empty()) {
        	res.push_back(minHeap.top());
        	minHeap.pop();
        }
        return res;
    }
};


//faster and less space complexity
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        if(k == 0 || nums1.empty() || nums2.empty()) return res;
        auto cmp = [&nums1, &nums2] (pair<int, int> a, pair<int, int> b) {
        	return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        minHeap.emplace(0, 0);
        while(k-- && !minHeap.empty()) {
        	auto idx_pair = minHeap.top();
        	minHeap.pop();
        	res.emplace_back(nums1[idx_pair.first], nums2[idx_pair.second]);
        	if(idx_pair.first+1 < nums1.size()) {
        		minHeap.emplace(idx_pair.first+1, j);
        	}
        	if(idx_pair.first == 0 && idx_pair.second+1 < nums2.size()) {
        		minHeap.emplace(idx_pair.first, idx_pair.second+1);
        	}
        }
        return res;
    }
};