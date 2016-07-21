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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight) {
    	if(preLeft > preRight || inLeft > inRight) return NULL;
    	TreeNode* cur = new TreeNode(preorder[preLeft]);
    	int i;
    	for(i = inLeft; i <= inRight; ++i) {
    		if(inorder[i] == cur->val) break;
    	}
    	cur->left = build(preorder, preLeft+1, preLeft+i-inLeft, inorder, inLeft, i-1);
    	cur->right = build(preorder, preLeft+i-inLeft+1, preRight, inorder, i+1, inRight);
    	return cur;
    }
};

//iteration, hard to understand
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  		stack<TreeNode*> s;
  		if(preorder.empty()) return NULL;
  		TreeNode* root = new TreeNode(preorder[0]);
  		s.push(root);
  		int index = 0;
  		for(int i = 1; i < preorder.size(); ++i) {
  			TreeNode* cur = s.top();
  			if(s.top()->val != inorder[index]) {
  				cur->left = new TreeNode(preorder[i]);
  				s.push(cur->left);
  			} 
  			else {
  				while(!s.empty() && s.top()->val == inorder[index]) {
  					cur = s.top();
  					s.pop();
  					index++;
  				}
  				if(index < inorder.size()) {
  					cur->right = new TreeNode(preorder[i]);
  					s.push(cur->right);
  				}
  			}
  		}
  		return root;
    }
};


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