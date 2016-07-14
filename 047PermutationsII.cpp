class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	if(nums.size() == 0) return vector<vector<int>>(1, vector<int>());
    	set<vector<int>> res;
    	int first = nums[0];
    	nums.erase(nums.begin());
    	vector<vector<int>> words = permuteUnique(nums);
    	for(auto word : words) {
    		for(int i = 0; i <= word.size(); ++i) {
    			if(word.size() == 0 || i == word.size() || first != word[i]) {
    				word.insert(word.begin()+i, first);
    				res.insert(word);
    				word.erase(word.begin()+i);
    			}
    			
    		}
    	}
    	return vector<vector<int>>(res.begin(), res.end());
	}
};


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    	vector<vector<int>> res;
    	permuteDFS(nums, res, 0);
    	return res;
	}

	void permuteDFS(vector<int> nums, vector<vector<int>>& res, int start) {	//nums不能为引用
		if(start == nums.size()-1) {
			res.push_back(nums);
			return;
		}
		for(int i = start; i < nums.size(); ++i) {
			if(i == start || nums[i] != nums[start]){
				swap(nums[start], nums[i]);
				permuteDFS(nums, res, start+1);
			}
		}
	}
};


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	vector<vector<int>> res;
    	vector<int> out;
    	map<int, int> num_times;
    	for(auto num : nums) {
    		if(num_times.find(num) == num_times.end())
    			num_times[num] = 0;
    		num_times[num]++;
    	}
    	permuteDFS(num_times, out, res, nums.size());
    	return res;
	}
	void permuteDFS(map<int, int> num_times, vector<int>& out, vector<vector<int>>& res, int n) {
		if(out.size() == n) {
			res.push_back(out);
			return;
		}
		for(auto &num : num_times) {
			if(num.second == 0) continue;
			out.push_back(num.first);
			num.second--;
			permuteDFS(num_times, out, res, n);
			out.pop_back();
			num.second++;
		}
	}
};
