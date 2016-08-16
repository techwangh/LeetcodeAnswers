/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	if(!head || !head->next) return true;

        ListNode *slow = head, *fast = head, *pre;
        while(fast && fast->next) {
        	pre = slow;
        	fast = fast->next->next;
        	slow = slow->next;
        }
        pre->next = NULL;
        ListNode *head1, *head2;
        head1 = reverseList(head);
        head2 = fast ? slow->next : slow;

        while(head1) {
        	if(head1->val != head2->val) return false;
        	head1 = head1->next;
        	head2 = head2->next;
        }
        return true;

    }

    ListNode* reverseList(ListNode* head) {
    	ListNode *pre = NULL, *cur = head;
    	while(cur) {
    		ListNode* next = cur->next;
    		cur->next = pre;
    		pre = cur;
    		cur = next;
    	}
    	return pre;
    }
};