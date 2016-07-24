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
    bool hasPathSum(TreeNode* root, int sum) {
        return pathSum(root, sum, 0);
    }

	bool pathSum(TreeNode* root, int num, int tmpNum) {
	    if(!root) return false;
		if(!root->left && !root->right) {
			if(tmpNum + root->val == num) return true;
		}
		return pathSum(root->left, num, tmpNum + root->val) || pathSum(root->right, num, tmpNum + root->val);
	}    
};