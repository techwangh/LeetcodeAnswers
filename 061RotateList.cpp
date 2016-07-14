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
    ListNode* rotateRight(ListNode* head, int k) {
    	if(!head) return head;
        int length = 0;
        ListNode *node = head, *pre;
        while(node) {
        	length++;
        	pre = node;
        	node = node->next;
        }
        if(k == 0 || k == length) return head;
        k %= length;
        pre->next = head;
        node = head;
        int i = 0; 
        while(i+1 != length - k) {
        	i++;
        	node = node->next;
        }
        head = node->next;
        node->next = NULL;
        return head;
    }
};