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
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if(k == 1) return head;
    	ListNode dummy(-1);
    	ListNode *prevEnd = &dummy;
        ListNode *left = head, *right = head;
        int count = 0;
        while(right) {
	        while(right && count < k) {
	        	count++;
	        	right = right->next;
	        }
	        if(count == k) {
	        	ListNode* nextHead = reverseList(left, right);
	        	prevEnd->next = nextHead;
	        	prevEnd = left;
		        left = right;
		        count = 0; 
	        }
	    }
	    prevEnd->next = left;
	    return dummy.next;
    }

    ListNode* reverseList(ListNode* left, ListNode*right) {		//[left, right)
    	ListNode *first, *second, *third;
    	first = left;
    	second = first->next;
    	third = second->next;
    	while(second != right) {
    		second->next = first;
    		first = second;
    		second = third;
    		third = third->next;
    	}
    	return first;	//head of subList
    }
};

//recursion and more concise
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
  		ListNode* cur = head;
  		for (int i = 0; i < k; ++i) {
  			if(!cur) return head;
  			cur = cur->next;
  		}
  		ListNode* newHead = reverseList2(head, cur);
  		head->next = reverseKGroup(cur, k);
  		return newHead;
    }

    ListNode* reverseList2(ListNode* left, ListNode* right) {	//[left,right)
    	ListNode* pre = right;
    	ListNode* last;
    	while(left != right) {
    		last = left->next;
    		left->next = pre;
    		pre = left;
    		left = last;
    	}
    	return pre;
    }
};