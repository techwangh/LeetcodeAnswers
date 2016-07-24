/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
// Recursion, more than constant space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        if (root->left) {
            root->left->next = root->right;
            root->right->next = root->next? root->next->left : NULL;
            connect(root->left);
            connect(root->right);
        }
        
    }
};


class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(!root) return;
  		TreeLinkNode *first, *cur = root;
  		while(cur->left) {
  			first = cur;
  			while(cur) {
  				cur->left->next = cur->right;
  				cur->right->next = cur->next ? cur->next->left : NULL;
  				cur = cur->next;
  			}
  			cur = first->left;
  		}
    }
};