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
    int sumNumbers(TreeNode* root) {
    	if(!root) return 0;
    	int sum = 0;
        calSum(root, sum, root->val);
        return sum;
    }

    void calSum(TreeNode* root, int& sum, int& path) {
    	if(!root->left && !root->right) {
    		sum += path;
    	}
    	if(root->left) {
    		path = path*10 + root->left->val;
    		calSum(root->left, sum, path);
    		path /= 10;
    	}
    	if(root->right) {
    		path = path*10 + root->right->val;
    		calSum(root->right, sum, path);
    		path /= 10;
    	}
    }
};