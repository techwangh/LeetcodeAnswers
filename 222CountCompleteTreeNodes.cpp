/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //TLE..这种算法适合任意二叉树，相当于遍历一遍二叉树
class Solution {
public:
    int countNodes(TreeNode* root) {
        int res = 0;
        count(root, res);
        return res;
    }
    
    void count(TreeNode* root, int& num) {
        if(root) {
            num++;
            count(root->left, num);
            count(root->right, num);
        }
    }
};


class Solution {
public:
    int countNodes(TreeNode* root) {
        TreeNode *pleft = root, *pright = root;
        int leftDep = 0, rightDep = 0; 
        while(pleft) {
            leftDep++;
            pleft = pleft->left;
        }
        while(pright) {
            rightDep++;
            pright = pright->right;
        }
        if(leftDep == rightDep)
            return pow(2, leftDep)-1;
        else
            return countNodes(root->left, root->right) + 1;

    }
};