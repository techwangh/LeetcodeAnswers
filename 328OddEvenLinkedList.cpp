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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *tmp = head->next;
        ListNode *node1 = head, *node2 = head->next;
        while(node2) {
        	node1->next = node2->next;
        	if(node1->next) {
        		node1 = node1->next;
        		node2->next = node1->next;
        		node2 = node2->next;
        	}
        	else break;
        }
        node1->next = tmp;
        return head;
    }
};