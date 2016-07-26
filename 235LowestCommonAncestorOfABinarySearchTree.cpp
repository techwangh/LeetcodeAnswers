/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //recursion
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < root->val && q->val < root->val)
        	return lowestCommonAncestor(root->left, p, q);
        else if(p->val > root->val && q->val > root->val)
        	return lowestCommonAncestor(root->right, p, q);
        else 
        	return root;
    }
};

//iteration
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	while(true) {
    		if(root->val < min(p->val, q->val))
    			root = root->right;
    		else if(root->val > max(p->val, q->val))
    			root = root->left;
    		else
    			break;
    	}
    	return root;
    }
};