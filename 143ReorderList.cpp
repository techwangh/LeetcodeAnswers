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
    void reorderList(ListNode* head) {
    	if(!head || !head->next || !head->next->next) return;
        ListNode *fast = head, *slow = head, *head1 = head, *head2;
        while(fast->next && fast->next->next) {
        	slow = slow->next;
        	fast = fast->next->next;
        }
        head2 = slow->next;
        slow->next = NULL;

        ListNode *pre = NULL, *last = head2;
        while(last) {
            ListNode *next = last->next;
            last->next = pre;
            pre = last;
            last = next;
        }
        head2 = pre;
        ListNode *node1 = head1, *node2 = head2;
        while(node2) {
        	ListNode* tmp = node2->next;
        	node2->next = node1->next;
        	node1->next = node2;
        	node1 = node2->next;
        	node2 = tmp;
        }
    }
};