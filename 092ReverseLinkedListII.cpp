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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if(m == n) return head;
    	ListNode dummy(-1);
        ListNode *node = &dummy;
        node->next = head;
        int count = 0;
        while(count+1 < m) {
        	node = node->next;
        	count++;
        }
        count++;
        ListNode *first, *second, *third;
        first = node->next;
        second = first->next; 
        third = second->next;
        while(count < n) {
        	second->next = first;
        	first = second;
        	second = third;
        	if(third) third = third->next;
        	count++;
        }
        node->next->next = second;
        node->next = first;
        return dummy.next;
    }
};