//TLE
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        for(int i = 0; i < int(nums.size())-1; ++i) {
            for(int j = i+1; j < nums.size(); ++j) {
                if(nums[i] > nums[j]) res[i]++;
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t, res(nums.size(), 0);
        for(int i = nums.size()-1; i >= 0; --i) {
        	int left = 0, right = t.size();
        	while(left < right) {
        		int mid = (left + right) / 2;
        		if(nums[i] <= t[mid]) right = mid;
        		else left = mid + 1;
        	}
        	res[i] = right;
        	t.insert(t.begin() + right, nums[i]);
        }
        return res;
    }
};


//use stl functions
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t(nums.size()), res(nums.size(), 0);
        for(int i = nums.size()-1; i >= 0; --i) {
        	int pos = distance(t.begin(), lower_bound(t.begin(), t.end(), nums[i]));
        	res[i] = pos;
        	t.insert(t.begin() + pos, nums[i]);
        }
        return res;
	}
};


class Solution {
public:
  	struct TreeNode
  	{
  		int smaller, val;
  		TreeNode *left, *right;
  		TreeNode(int v, int s) : val(v), smaller(s), left(NULL), right(NULL) {}
  	};

  	int insert(TreeNode*& root, int val) {
  		if(!root) {
  			root = new TreeNode(val, 0);
  			return 0;
  		}
  		if(val < root->val) {
  			root->smaller++;
  			return insert(root->left, val);
  		}
  		else {
  			return insert(root->right, val) + root->smaller + (val > root->val ? 1 : 0);
  		}
  	}

    vector<int> countSmaller(vector<int>& nums) {
    	std::vector<int> res(nums.size());
    	TreeNode* root = NULL;
    	for(int i = nums.size()-1; i >= 0; --i) {
    		res[i] = insert(root, nums[i]);
    	}
    	return res;
    }
};