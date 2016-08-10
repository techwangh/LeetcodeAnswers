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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode *a = headA, *b = headB;
        while(a != b) {
        	a = a ? a->next : headB;
        	b = b ? b->next : headA; 
        }
        return a;
    }
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
		int n1 = 0, n2 = 0;
		ListNode *a = headA, *b = headB;
		while(a) {
			a = a->next;
			n1++;
		}        
		while(b) {
			b = b->next;
			n2++;
		}
		a = headA;
		b = headB;
		int diff = abs(n1 - n2);
		if(n1 > n2) {
			while(diff--) a = a->next;
		}
		else {
			while(diff--) b = b->next;
		}
		while(a != b) {
			a = a->next;
			b = b->next;
		}
		return a;
    }
};