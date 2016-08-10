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
    ListNode* insertionSortList(ListNode* head) {
    	if(!head || !head->next) return head;
        ListNode *cur = head, *pre, *node = head->next;
        head->next = NULL;
        while(node) {
        	pre = NULL;
        	cur = head;
        	ListNode* next = node->next;
        	while(cur && node->val > cur->val) {
        		pre = cur;
        		cur = cur->next;
        	}
        	if(cur == head) {
        		node->next = head;
        		head = node;
        	}
        	else {
	        	pre->next = node;
	        	node->next = cur;
        	}
        	node = next;
        }
        return head;
    }
};

//faster one
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
    	ListNode *new_head = new ListNode(0);
    	new_head->next = head;
    	ListNode *cur = head, *pre = new_head;
    	while(cur) {
    		if(cur->next && cur->next->val < cur->val) {
    			while(pre->next && pre->next->val < cur->next->val) 
    				pre = pre->next;
    			ListNode *tmp = pre->next;
    			pre->next = cur->next;
    			cur->next = cur->next->next;
    			pre->next->next = tmp;
    			pre = new_head;
    		}
    		else
    			cur = cur->next;
    	}
    	return new_head->next;
    }
};