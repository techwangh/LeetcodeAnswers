class Solution {
public:
    Solution(vector<int> nums) : m_nums(nums), e(time(0)) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return m_nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
    	std::vector<int> res = m_nums;
        for(int i = res.size()-1; i >= 0; --i) {
    		uniform_int_distribution<decltype(i)> u(0, i);
        	swap(res[i], res[u(e)]);
        }
        return res;
    }

private:
	vector<int> m_nums;
	default_random_engine e;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */