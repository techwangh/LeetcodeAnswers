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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ppath, qpath;
        bool found = false;
        findPath(root, p, ppath, found);
        found = false;
        findPath(root, q, qpath, found);

        int end = min(ppath.size(), qpath.size());
        for(int i = 1; i < end; ++i) {
        	if(ppath[i] != qpath[i])
        		return ppath[i-1];
        }
        return ppath[end-1];
    }

    void findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path, bool& found) {
    	if(!root) return; 
    	if(!found) {
    		path.push_back(root);
    		if(root == target) {
    			found = true;
    			return;
    		}
    		findPath(root->left, target, path, found);
    		findPath(root->right, target, path, found);
    		if(!found) path.pop_back();
    	}
    }
};

//very concise one, hard to understand
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  		if(!root || p == root || q == root) return root;
  		TreeNode* left = lowestCommonAncestor(root->left, p, q);
  		TreeNode* right = lowestCommonAncestor(root->right, p, q);
  		if(left && right) return root;
  		return left ? left : right;
    }
};

//same as the above, but faster
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  		if(!root || p == root || q == root) return root;
  		TreeNode* left = lowestCommonAncestor(root->left, p, q);
  		if(left && left != p && left != q) return left;
  		TreeNode* right = lowestCommonAncestor(root->right, p, q);
  		if(right && right != p && right != q) return right;
  		if(left && right) return root;
  		return left ? left : right;
    }
};