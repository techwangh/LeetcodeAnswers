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
    vector<string> binaryTreePaths(TreeNode* root) {
    	vector<string> res;
        if(!root) return res;
        string out;
        treePaths(root, res, out);
        return res;
    }

    void treePaths(TreeNode* root, vector<string>& res, string out) {
    	out = out + "->";
    	out += int2string(root->val);
    	if(!root->left && !root->right) {
    	    out.erase(0, 2);
    	    res.push_back(out);
    	}
    		
    	if(root->left)
    		treePaths(root->left, res, out);
    	if(root->right)
    		treePaths(root->right, res, out);
    }
    
    string int2string(int val) {	//there is a std function called to_string();
        int tmp = abs(val);
        string s;
        while(tmp) {
            s.push_back('0' + tmp%10);
            tmp /= 10;
        }
        if(val < 0) s.push_back('-');
        reverse(s.begin(), s.end());
        return s;
    }
};