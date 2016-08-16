class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res, heights;
        for(auto b : buildings) {
        	heights.push_back({b[0], -b[2]});
        	heights.push_back({b[1],  b[2]});
        }
        sort(heights.begin(), heights.end());
        multiset<int> h;
        h.insert(0);
        int pre = 0, cur = 0;
        for(auto &height : heights) {
        	if(height.second < 0) h.insert(-height.second);
        	else h.erase(h.find(height.second));
        	cur = *h.rbegin();
        	if(cur != pre) {
        		res.push_back({height.first, cur});
        		pre = cur;
        	}
        }
        return res;
    }
};