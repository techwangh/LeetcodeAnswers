class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m);
        int i = 0;
        for(int j = 0; j < n; ++j) {
            while(i < nums1.size() && nums2[j] > nums1[i]) ++i;
            nums1.insert(nums1.begin()+i, nums2[j]);
        }
    }
};


//another solution
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int count = m+n-1;
        n--; m--;
        while(n >= 0 && m >= 0)
        	nums1[count--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        while(n >= 0)
        	nums1[count--] = nums2[n--];
    }
};