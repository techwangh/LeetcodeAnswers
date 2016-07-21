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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while(!s1.empty() || !s2.empty()) {
        	vector<int> out;
        	while(!s1.empty()) {
        		TreeNode* node = s1.top();
        		out.push_back(node->val);
        		s1.pop();
        		if(node->left) s2.push(node->left);
        		if(node->right) s2.push(node->right);
        	}
        	if(out.size() != 0) {
        		res.push_back(out);
        		out.clear();
        	}

        	while(!s2.empty()) {
        		TreeNode* node = s2.top();
        		out.push_back(node->val);
        		s2.pop();
        		if(node->right) s1.push(node->right);
        		if(node->left) s1.push(node->left);
        	}
        	if(out.size() != 0)
        		res.push_back(out);
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
  		queue<TreeNode*> q;
  		int lineNum = 1;
        if(root) q.push(root);
        while(!q.empty()) {
        	int end = q.size();
        	vector<int> out;
        	for(int i = 0; i < end; ++i) {
        		TreeNode* node = q.front();
        		out.push_back(node->val);
        		q.pop();
        		if(node->left) q.push(node->left);
        		if(node->right) q.push(node->right);
        	}
        	if(lineNum % 2 == 0) reverse(out.begin(), out.end());
        	res.push_back(out);
        	lineNum++;
        }
        return res;
    }
};