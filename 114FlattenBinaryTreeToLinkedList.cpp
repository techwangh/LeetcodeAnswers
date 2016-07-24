/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //iteration
class Solution {
public:
    void flatten(TreeNode* root) {
        while(root) {
        	if(root->left) {
	        	TreeNode* p = root->left;
	        	while(p->right) 
	        		p = p->right;
	        	p->right = root->right;
	        	root->right = root->left;
	        	root->left = NULL;
        	}
        	root = root->right;
        }
    }
};

//recursion
class Solution {
public:
    void flatten(TreeNode* root) {
  		if(!root) return;
  		if(root->left) flatten(root->left);
  		if(root->right) flatten(root->right);

  		if(root->left) {
	  		TreeNode* p = root->left;
	  		while(p->right) p = p->right;
	  		p->right = root->right;
	  		root->right = root->left;
	  		root->left = NULL;
  		}
    }
};