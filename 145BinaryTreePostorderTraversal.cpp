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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }

    void postorder(TreeNode* root, vector<int>& res) {
    	if(!root) return;
    	postorder(root->left, res);
    	postorder(root->right, res);
    	res.push_back(root->val);
    }
};

//iterate
//当遍历一个节点时，要么左右都为空，要么左右都遍历完了，就可以将此节点插入
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* head;
        s.push(root);
        while(!s.empty()) {
        	TreeNode* top = s.top();
        	if((!top->left && !top->right) || top->left == head || top->right == head) {
        		res.push_back(top->val);
        		s.pop();
        		head = top;
        	}
        	else {
        		if(top->right) s.push(top->right);
        		if(top->left) s.push(top->left);
        	}
        }
        return res;
    }
};