/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *cur = root, *prenode;
        while(cur) {
        	while(cur && !cur->left && !cur->right) cur = cur->next;
        	if(!cur) return;	//最后一行已经处理完了
        	TreeLinkNode* first = cur;
        	if(cur->left && cur->right) {
        		cur->left->next = cur->right;
        		prenode = cur->right;
        	}
        	else 
        		prenode = cur->left ? cur->left : cur->right;
        	cur = cur->next;
        	while(cur) {
        		if(cur->left && cur->right) {
        			prenode->next = cur->left;
        			cur->left->next = cur->right;
        			prenode = cur->right;
        		}
        		else if(cur->left) {
        			prenode->next = cur->left;
        			prenode = cur->left;
        		}
        		else if(cur->right) {
        			prenode->next = cur->right;
        			prenode = cur->right;
        		}
        		cur = cur->next;
        	}
        	cur = first->left ? first->left : first->right;
        }
    }
};

//recursion
class Solution {
public:
    void connect(TreeLinkNode *root) {
  		if(!root) return;
  		TreeLinkNode* p = root->next;
  		while(p) {
  			if(p->left) {
  				p = p->left;
  				break;
  			}
  			if(p->right) {
  				p = p->right;
  				break;
  			}
  			p = p->next;
  		}
  		if(root->right) root->right->next = p;
  		if(root->left) root->left->next = root->right ? root->right : p;
  		connect(root->right);
  		connect(root->left);
    }
};