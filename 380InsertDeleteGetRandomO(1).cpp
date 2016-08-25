class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() : e(time(0)) {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) != m.end()) return false;
        vec.push_back(val);
        m[val] = vec.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;
        if(val != vec.back()) {
            m[vec.back()] = m[val];
            swap(vec[m[val]], vec.back());
        }
        m.erase(val);
        vec.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        uniform_int_distribution<int> u(0, vec.size()-1);
        return vec[u(e)];
    }

private:
    unordered_map<int, int> m;
    vector<int> vec;
    default_random_engine e;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */