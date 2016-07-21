/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //iterate
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	if(!root) return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()) {
        	TreeNode *top1 = q1.front(), *top2 = q2.front();
        	q1.pop();
        	q2.pop();
        	if(!top1 && !top2) continue;
        	if((top1 && !top2) || (!top1 && top2)) return false;
        	if(top1->val != top2->val) return false;

        	q1.push(top1->left);
        	q1.push(top1->right);
        	q2.push(top2->right);
        	q2.push(top2->left);
        }
        if(!q1.empty() || !q2.empty())
        	return false;
        else 
        	return true; 
    }
};

//recursive
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	if(!root) return true;
  		return isSymmetricDFS(root->left, root->right);
    }

	bool isSymmetricDFS(TreeNode* left, TreeNode* right) {
		if(!left && !right) return true;
		if((left && !right) || (!left && right) || left->val != right->val) return false;
		return isSymmetricDFS(left->left, right->right) && isSymmetricDFS(left->right, right->left);
	}
};