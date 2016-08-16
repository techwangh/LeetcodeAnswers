//why this is a "hard" problem
class MedianFinder {
public:
	MedianFinder() : size(0) {}

    // Adds a number into the data structure.
    void addNum(int num) {
        nums.insert(nums.begin() + findPos(num), num);
        size++;
    }

    // Returns the median of current data stream
    double findMedian() {
    	double res = 0;
        if(size % 2 == 0) {
        	res = (double(nums[size/2]) + double(nums[size/2-1])) / 2;
        }
        else {
        	res = nums[size/2];
        }
        return res;
    }



private:
	int findPos(int num) {
		int left = 0, right = int(nums.size())-1;
		while(left <= right) {
			int mid = left + (right-left) / 2;
			if(nums[mid] == num) return mid;
			else if(nums[mid] < num) left = mid + 1;
			else right = mid - 1;
		}
		return left;
	}

	vector<int> nums;
	int size;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();