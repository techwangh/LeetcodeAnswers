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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preoder(root, res);
        return res;
    }

    void preoder(TreeNode* root, vector<int>& res) {
    	if(!root) return;
    	res.push_back(root->val);
    	preoder(root->left, res);
    	preoder(root->right, res);
    }
};

//iterate
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !p.empty()) {
        	while(p) {
        		res.push_back(p->val);
        		s.push(p);
        		p = p->left;
        	}
        	p = s.top();
        	s.pop();
        	p = p->right;
        }
        return res;
    }
};