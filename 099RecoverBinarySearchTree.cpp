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
	TreeNode *pre, *first, *second;
    void recoverTree(TreeNode* root) {
    	pre = NULL;
    	first = NULL;
    	second = NULL;
    	inorder(root);
    	if(first && second) swap(first->val, second->val);
    }

    void inorder(TreeNode* root) {
    	if(!root) return;
    	inorder(root->left);
    	if(pre && pre->val > root->val) {
    		if(!first) first = pre;		//被交换的两个肯定是前面一个大了，后面一个小了，所以first = pre, second = root;
    		second = root;
    	}
    	pre = root;
    	inorder(root->right);
    }
};