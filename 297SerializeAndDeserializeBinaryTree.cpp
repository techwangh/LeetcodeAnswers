/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	ostringstream out;
    	queue<TreeNode*> q;
    	if(root) q.push(root);
    	while(!q.empty()) {
    		TreeNode* node = q.front();
    		q.pop();
    		if(node) {
    			out << node->val << ' ';
    			q.push(node->left);
    			q.push(node->right);
    		} else
    			out << '#' << ' ';
    	}
    	return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	if(data.empty()) return nullptr;
    	istringstream in(data);
    	string val;
    	in >> val;
    	TreeNode* root = new TreeNode(stoi(val));
    	queue<TreeNode*> q;
    	q.push(root);
    	while(!q.empty()) {
    		TreeNode* cur = q.front();
    		q.pop();
    		if(!(in >> val)) break;
    		if(val != "#") {
    			TreeNode* node = new TreeNode(stoi(val));
    			cur->left = node;
    			q.push(node);
    		}
    		if(!(in >> val)) break;
    		if(val != "#") {
    			TreeNode* node = new TreeNode(stoi(val));
    			cur->right = node;
    			q.push(node);
    		}
    	}
    	return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        preorderSerialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return preorderDeserialize(in);
    }
    
private:
	void preorderSerialize(TreeNode* root, ostringstream& out) {
		if(!root) out << '#' << ' ';
		else {
			out << root->val << ' ';
			preorderSerialize(root->left, out);
			preorderSerialize(root->right, out);
		}
	}
	
	TreeNode* preorderDeserialize(istringstream& in) {
		string val;
		if(!(in >> val) || val == "#") return nullptr;
		TreeNode* root = new TreeNode(stoi(val));
		root->left = preorderDeserialize(in);
		root->right = preorderDeserialize(in);
		return root;
	}
	
};