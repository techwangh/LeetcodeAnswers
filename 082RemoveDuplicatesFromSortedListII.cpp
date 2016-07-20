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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1);
        ListNode* back = &dummy;
        int count = 1;
        while(head) {
        	while(head->next && head->val == head->next->val) {
        		head = head->next;
        		count++;
        	}
        	if(count == 1) {
        		back->next = head;
        		head = head->next;
        		back = back->next;
        		back->next = NULL;
        	} else {
        		count = 1;
        		head = head->next;
        	}
        }
        return dummy.next;
    }
};


//more concise one
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1);
        ListNode* pre = &dummy;
        pre->next = head;
        while(pre->next) {
        	ListNode* cur = pre->next;
        	while(cur->next && cur->val == cur->next->val)
        		cur = cur->next;
        	if(cur != pre->next)
        		pre->next = cur->next;
        	else
        		pre = pre->next;
        }
        return dummy.next;
    }
};