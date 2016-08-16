class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks(words.size(), 0);
        int res = 0;
        for(int i = 0; i < words.size(); ++i) {
        	for(auto c : words[i]) {
        		masks[i] |= 1 << (c - 'a');
        	}
        	for(int j = 0; j < i; ++j) {
        		if(!(masks[i] & masks[j]))
        			res = max(res, int(words[i].size() * words[j].size()));
        	}
        }
        return res;
    }
};