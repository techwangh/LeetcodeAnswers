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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
    	if(!root) return res;
        vector<int> out;
        out.push_back(root->val);
        path(root, sum, res, out);
        return res;
    }

    void path(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& out) {
    	if(!root) return;
    	if(!root->left && !root->right && root->val == sum) 
    		res.push_back(out);
    	if(root->left) {
    		out.push_back(root->left->val);
    		path(root->left, sum-root->val, res, out);
    		out.pop_back();
    	}
    	if(root->right) {
    		out.push_back(root->right->val);
    		path(root->right, sum-root->val, res, out);
    		out.pop_back();
    	}
    }
};