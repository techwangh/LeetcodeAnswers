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
    bool isValidBST(TreeNode* root) {
        long min = long(INT_MIN)-1, max = long(INT_MAX)+1;
        return isValid(root, min, max);
    }

    bool isValid(TreeNode* root, long min, long max) {
    	if(!root) return true;
    	if(root->val <= min || root_val >= max)
    		return false;
    	return isValid(root->left, min, root->val) && isValid(root->right, root->val, max);
    }
};