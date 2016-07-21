/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        std::vector<int> nums;
        while(head) {
        	nums.push_back(head->val);
        	head = head->next;
        }
        return arrayToBST(nums, 0, nums.size()-1);
    }

    TreeNode* arrayToBST(vector<int>& nums, int left, int right) {
    	if(left > right) return NULL;
    	int mid = (left + right) / 2;
    	TreeNode* cur = new TreeNode(nums[mid]);
    	cur->left = arrayToBST(nums, left, mid-1);
    	cur->right = arrayToBST(nums, mid+1, right);
    	return cur;
    }
};


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
  		if(!head) return NULL;
  		if(!head->next) {
  		    TreeNode* node = new TreeNode(head->val);
  		    return node;
  		}
  		ListNode *pre = head, *mid = head, *end = head;
  		while(end->next && end->next->next) {
  		    pre = mid;
  			mid = mid->next;
  			end = end->next->next;
  		}
  		TreeNode* cur = new TreeNode(mid->val);
  		ListNode* rightHead = mid->next;
  		pre->next = NULL;
  		if(pre != mid) cur->left = sortedListToBST(head);
  		cur->right = sortedListToBST(rightHead);
  		return cur;
    }
};