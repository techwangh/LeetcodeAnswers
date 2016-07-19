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
    ListNode* partition(ListNode* head, int x) {
    	ListNode dummy1(-1), dummy2(-1);
    	ListNode *back1 = &dummy1, *back2 = &dummy2;
        while(head) {
        	if(head->val < x) {
        		back1->next = head;
        		back1 = head;
        	}
        	else {
        		back2->next = head;
        		back2 = head;
        	}
        	head = head->next;
        }
        back1->next = dummy2.next;
        back2->next = NULL;
        return dummy1.next;
    }
};