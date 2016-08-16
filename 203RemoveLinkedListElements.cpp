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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* new_head = new ListNode(-1);
        new_head->next = head;
        ListNode *pre = new_head, *cur = head;
        while(cur) {
            if(cur->val == val) {
                pre->next = cur->next;
            }
            else {
                pre = cur;
            }
            
            cur = cur->next;
        }
        return new_head->next;
    }
};