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
    int rob(TreeNode* root) {
    	unordered_map<TreeNode*, int> m;
    	return robDFS(root, m);

    }

    int robDFS(TreeNode* root, unordered_map<TreeNode*, int>& m) {
    	if(!root) return 0;
    	if(m.find(root) != m.end()) return m[root];
    	int val = 0;
    	if(root->left) 
        	val += robDFS(root->left->left, m) + robDFS(root->left->right, m);
        if(root->right)
        	val += robDFS(root->right->left, m) + robDFS(root->right->right, m);
        m[root] = max(val + root->val, robDFS(root->left, m) + robDFS(root->right, m));
        return m[root];
    }
};


class Solution {
public:
    int rob(TreeNode* root) {
    	vector<int> res = robDFS(root);
    	return max(res[0], res[1]);
    }

    vector<int> robDFS(TreeNode* root) {
    	if(!root) return vector<int>(2, 0);
    	vector<int> left, right, res(2, 0);	//res[0]:不带本节点的最大值，res[1]:带本节点的最大值
    	left = robDFS(root->left);
    	right = robDFS(root->right);
    	res[0] = max(left[0], left[1]) + max(right[0], right[1]);
    	res[1] = left[0] + right[0] + root->val;
    	return res;
    }
};


//
class Solution {
public:
    int rob(TreeNode* root) {
    	auto p = robDFS(root);
    	return max(p.first, p.second); 
    }

    pair<int, int> robDFS(TreeNode* root) {
    	if(!root) return {0, 0};
    	auto left = robDFS(root->left);
    	auto right = robDFS(root->right);
    	return make_pair(max(left.first, left.second) + max(right.first, right.second),
    					 root->val + left.first + right.first);
    }
};