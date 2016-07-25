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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty()) {
        	while(p) {
        		s.push(p);
        		p = p->left;
        	}
        	p = s.top();
        	s.pop();
        	k--;
        	if(k == 0) return p->val;
        	p = p->right;
        }
        return 0;
    }
};

//recursion, hard to understand
class Solution {
public:
    int kthSmallest(TreeNode* root, int& k) {
		if(!root) return -1;
		int val = kthSmallest(root->left, k);
		if(!k) return val;
		if(!--k) return root->val;
		return kthSmallest(root->right, k);
    }
};