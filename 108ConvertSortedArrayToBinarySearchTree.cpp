/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrayToBST(nums, 0, nums.size()-1);
    }

    TreeNode* arrayToBST(vector<int>& nums, int left, int right) {
    	if(left > right) return NULL;
    	int mid = (left + right) / 2;
    	TreeNode* cur = new TreeNode(nums[mid]);
    	cur->left = arrayToBST(nums, left, mid-1);
    	cur->right = arrayToBST(nums, mid+1, right);
    	return cur;
    }
};