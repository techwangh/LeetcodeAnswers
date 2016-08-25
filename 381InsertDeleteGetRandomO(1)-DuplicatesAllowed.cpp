class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() : e(time(0)) {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = m.find(val) == m.end;

        m[val].push_back(nums.size());
        nums.emplace_back(val, m[val].size()-1);

        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool res = m.find(val) != m.end;

        if(res) {
            auto last = nums.back();
            m[last.first][last.second] = m[val].back();
            nums[m[val].back()] = last;
            
            m[val].pop_back();
            if(m[val].empty()) m.erase(val);
            nums.pop_back();
        }
        return res;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        uniform_int_distribution<int> u(0, nums.size()-1);
        return nums[u(e)];
    }

private:
    unordered_map<int, vector<int>> m;
    vector<pair<int, int>> nums;
    default_random_engine e;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */


 ref:
 https://discuss.leetcode.com/topic/54381/c-128m-solution-real-o-1-solution