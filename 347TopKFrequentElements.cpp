class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        int maxVal = 0;
        for(auto n : nums) {
        	m[n]++;
        	maxVal = max(maxVal, m[n]);
        }
        vector<vector<int>> bucket(maxVal+1);
        for(auto a : m) {
        	bucket[a.second].push_back(a.first);
        }
        vector<int> res;
        for(int i = bucket.size()-1; i > 0 && res.size() < k; --i) {
        	for(auto a : bucket[i]) {
        		res.push_back(a);
        		if(res.size() == k) break;
        	}
        } 
        return res;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(auto n : nums) {
        	m[n]++;
        }        
        priority_queue<pair<int, int>> q;
        for(auto pair : m) {
        	q.emplace(pair.second, pair.first);
        }
        vector<int> res;
        while(k--) {
        	res.push_back(q.top().second);
        	q.pop();
        }
        return res;
    }
};