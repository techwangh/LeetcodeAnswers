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
    ListNode* sortList(ListNode* head) {
    	if(!head || !head->next) return head;
        ListNode *fast = head, *slow = head, *head1 = head, *head2;
        while(fast->next && fast->next->next) {
        	slow = slow->next;
        	fast = fast->next->next;
        }
        head2 = slow->next;
        slow->next = NULL;
        return merge(sortList(head1) sortList(head2));
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
    	ListNode *new_head = new ListNode(0);
    	ListNode *cur = new_head;
    	while(head1 && head2) {
    		if(head1->val < head2->val) {
    			cur->next = head1;
    			head1 = head1->next;
    		}
    		else {
    			cur->next = head2;
    			head2 = head2->next;
    		}
    		cur = cur->next;
    	}
    	cur->next = head1 ? head1 : head2;
    	return new_head->next;
    }
};