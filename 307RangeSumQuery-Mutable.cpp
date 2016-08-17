class NumArray {
public:
    NumArray(vector<int> &nums) {
        m_nums.resize(nums.size()+1);
        m_sums.resize(nums.size()+1);
        for(int i = 0; i < nums.size(); ++i) {
        	update(i, nums[i]);
        }
    }

    void update(int i, int val) {
        int diff = val - m_nums[i+1];
        for(int j = i+1; j < m_sums.size(); j += j &(-j)) {
        	m_sums[j] += diff;
        }
        m_nums[i+1] = val;
    }

    int sumRange(int i, int j) {
        return getSum(j) - getSum(i-1);
    }

    int getSum(int i) {
    	int sum = 0;
    	for(int j = i+1; j > 0; j -= j & (-j)) {
    		sum += m_sums[j];
    	}
    	return sum;
    }

private:
	vector<int> m_nums;
	vector<int> m_sums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);