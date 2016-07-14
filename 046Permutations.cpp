class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        vector<bool> visited(nums.size(), false);
        permuteDFS(nums, res, out, visited);
        return res;
    }

    void permuteDFS(vector<int>& nums, vector<vector<int>>& res, vector<int>& out, vector<bool>& visited) {
    	if(out.size() == nums.size()) {
    		res.push_back(out);
    		return;
    	}
    	for(int i = 0; i < nums.size(); ++i) {
    		if(!visited[i]) {
    			visited[i] = true;
    			out.push_back(nums[i]);
	    		permuteDFS(nums, res, out, visited);
	    		out.pop_back();
	    		visited[i] = false;
	    	}
    	}
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    	vector<vector<int>> res;
    	permuteDFS(nums, res, 0);
    	return res;
	}

	void permuteDFS(vector<int>& nums, vector<vector<int>>& res, int start) {
		if(start == nums.size()-1) {
			res.push_back(nums);
			return;
		}
		for(int i = start; i < nums.size(); ++i) {
			swap(nums[start], nums[i]);
			permuteDFS(nums, res, start+1);
			swap(nums[start], nums[i]);
		}
	}
};



class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    	if(nums.size() == 0) return vector<vector<int>>(1, vector<int>());
    	vector<vector<int>> res;
    	int first = nums[0];
    	nums.erase(nums.begin());
    	vector<vector<int>> words = permute(nums);
    	for(auto word : words) {
    		for(int i = 0; i <= word.size(); ++i) {
    			word.insert(word.begin()+i, first);
    			res.push_back(word);
    			word.erase(word.begin()+i);
    		}
    	}
    	return res;
    }
};