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
    int rob(TreeNode* root) {
    	unordered_map<TreeNode*, int> m;
    	return robDFS(root, m);

    }

    int robDFS(TreeNode* root, unordered_map<TreeNode*, int>& m) {
    	if(!root) return 0;
    	if(m.find(root) != m.end()) return m[root];
    	int val = 0;
    	if(root->left) 
        	val += robDFS(root->left->left, m) + robDFS(root->left->right, m);
        if(root->right)
        	val += robDFS(root->right->left, m) + robDFS(root->right->right, m);
        m[root] = max(val + root->val, robDFS(root->left, m) + robDFS(root->right, m));
        return m[root];
    }
};