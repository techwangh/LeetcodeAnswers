class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> m;
        for(auto ticket : tickets) {
        	m[ticket.first].insert(ticket.second);
        }
        dfs(m, "JFK", res);
        return vector<string>(res.rbegin(), res.rend());
    }

    void dfs(unordered_map<string, multiset<string>>& m, string s, vector<string>& res) {
    	while(!m[s].empty()) {
    		string next = *m[s].begin();
    		m[s].erase(m[s].begin());
    		dfs(m, next, res);
    	}
    	res.push_back(s);
    }

};