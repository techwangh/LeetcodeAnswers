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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	if(!l1) return l2;
    	if(!l2) return l1;

    	int carry = 0;
    	int sum = l1->val + l2->val;
    	ListNode *node = new ListNode(sum%10);
    	ListNode *head = node;
    	if(sum >= 10) carry = 1;
    	l1 = l1->next;
    	l2 = l2->next;

        while(l1 && l2) {
            sum = l1->val + l2->val + carry;
            ListNode *nextNode = new ListNode(sum % 10);
            node->next = nextNode;
            node = nextNode;
			carry = sum >= 10 ? 1 : 0;
			l1 = l1->next;
			l2 = l2->next;
        }
        while(l1) {
        	sum = l1->val + carry;
        	ListNode *nextNode = new ListNode(sum % 10);
            node->next = nextNode;
            node = nextNode;
			carry = sum >= 10 ? 1 : 0;
			l1 = l1->next;
        }
        while(l2) {
        	sum = l2->val + carry;
        	ListNode *nextNode = new ListNode(sum % 10);
            node->next = nextNode;
            node = nextNode;
			carry = sum >= 10 ? 1 : 0;
			l2 = l2->next;
        }
        if(carry == 1) {
        	ListNode *nextNode = new ListNode(carry);
            node->next = nextNode;
        }
        return head;
    }
};