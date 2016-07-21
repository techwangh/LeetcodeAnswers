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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
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
        	res.push_back(out);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//recursive, same as question 102
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    	vector<vector<int>> res;
  		levelOrderRecur(root, 0, res);
  		reverse(res.begin(), res.end());
  		return res;
    }
   	
   	void levelOrderRecur(TreeNode* root, int level, vector<vector<int>>& res) {
   		if(!root) return;
   		if(res.size() == level) 
   			res.push_back({});
   		res[level].push_back(root->val);
   		levelOrderRecur(root->left, level+1, res);
   		levelOrderRecur(root->right, level+1, res);
   	}
};