class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        vector<int>::const_iterator it1 = nums1.begin();
        vector<int>::const_iterator it2 = nums2.begin();
        while(it1 != nums1.end() && it2 != nums2.end()) {
        	if(*it1 <= *it2) {
        		nums.push_back(*it1);
        		++it1;
        	}else {
        		nums.push_back(*it2);
        		++it2;
        	}
        }
        while(it1 != nums1.end()) {
        	nums.push_back(*it1);
        	++it1;
        }
        while(it2 != nums2.end()) {
        	nums.push_back(*it2);
        	++it2;
        }
        int m = nums.size();
        if(m % 2 == 1) {
        	return nums[m/2];
        }else {
        	return (nums[m/2] + nums[m/2-1])/2.0;
        }
    }
};