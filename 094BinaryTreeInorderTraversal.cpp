/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> res;
    	if(!root) return res;
    	inorderTraversalDFS(root, res);
    	return res;
    }

    void inorderTraversalDFS(TreeNode* root, vector<int>& res) {
        if(root->left) inorderTraversalDFS(root->left, res);
		res.push_back(root->val);
		if(root->right) inorderTraversalDFS(root->right, res);    	
    }
};

//iterate, use stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> res;
    	stack<TreeNode*> s;
    	TreeNode* p = root;
    	while(p || !s.empty()) {
    		while(p) {
    			s.push(p);
    			p = p->next;
    		}
    		p = s.top();
    		s.pop();
    		res.push_back(p->val);
    		p = p->right;
    	}
    	return res;
    }
};