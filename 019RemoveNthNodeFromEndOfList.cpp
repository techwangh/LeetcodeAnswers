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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vecror<ListNode*> nodes(n+1, NULL);
        ListNode node = head;
        while(node != NULL) {
        	for(int i = 1; i <= n; ++i) 
        		nodes[i-1] = nodes[i];
        	nodes[n] = node;
        	node = node->next;
        }
        nodes.push_back(NULL);
        nodes[0]->next = nodes[2];
        return head;
    }
};