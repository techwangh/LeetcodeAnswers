/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //recursion
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode* build(vector<int>& inorder, int inLeft, int inRight, vector<int>& postorder, int postLeft, int postRight) {
    	if(inLeft > inRight || postLeft > postRight) return NULL;
    	TreeNode* cur = new TreeNode(postorder[postRight]);
    	int i;
    	for(i = inLeft; i <= inRight; ++i) {
    		if(inorder[i] == cur->val) break;
    	}
    	cur->left = build(inorder, inLeft, i-1, postorder, postLeft, postLeft+i-inLeft-1);
    	cur->right = build(inorder, i+1, inRight, postorder, postLeft+i-inLeft, postRight-1);
    	return cur;
    }
};

//iteration
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	stack<TreeNode*> s;
  		if(postorder.empty()) return NULL;
  		TreeNode* root = new TreeNode(postorder.back());
  		s.push(root);
  		int index = inorder.size()-1;
  		for(int i = postorder.size()-2; i >= 0; --i) {
  			TreeNode* cur = s.top();
  			if(cur->val != inorder[index]) {
  				cur->right = new TreeNode(postorder[i]);
  				s.push(cur->right);
  			}
  			else {
  				while(!s.empty() && s.top()->val == inorder[index]) {
  					cur = s.top();
  					s.pop();
  					index--;
  				}
  				if(index >= 0) {
  					cur->left = new TreeNode(postorder[i]);
  					s.push(cur->left);
  				}
  			}
  		}
  		return root;
  	}
};