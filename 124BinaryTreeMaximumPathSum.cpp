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
    int maxPathSum(TreeNode* root) {
        int  maxSum = INT_MIN;
        pathSum(root, maxSum);
        return maxSum;
    }

    int pathSum(TreeNode* root, int& maxSum) {
    	if(!root) return 0;
    	if(!root->left && !root->right) {
    		maxSum = max(maxSum, root->val);
    		return root->val;
    	} 
    	int leftMax = INT_MIN, rightMax = INT_MIN;
    	if(root->left) leftMax = pathSum(root->left);
    	if(root->right) rightMax = pathSum(root->right);

    	if(leftMax <= 0 && rightMax <= 0) {
    		maxSum = max(maxSum, root->val);
    		return root->val;
    	}
    	else if(leftMax > 0 && rightMax > 0) {
    		maxSum = max(maxSum, leftMax+rightMax+root->val);
    		return max(leftMax, rightMax) + root->val;
    	}
    	else {
    		maxSum = max(maxSum, max(leftMax, rightMax)+root->val);
    		return max(leftMax, rightMax)+root->val;
    	}
    }
};


//more concise one
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int  maxSum = INT_MIN;
        pathSum(root, maxSum);
        return maxSum;
    }

    int pathSum(TreeNode* root, int& maxSum) {
    	if(!root) return 0;
    	int leftMax = pathSum(root->left, maxSum);
    	int rightMax = pathSum(root->right, maxSum);
    	int top = root->val + (leftMax > 0 ? leftMax : 0) + (rightMax > 0 ? rightMax : 0);
    	maxSum = max(maxSum, top);
    	return max(leftMax, rightMax) > 0 ? max(leftMax, rightMax) + root->val : root->val;
    }
};