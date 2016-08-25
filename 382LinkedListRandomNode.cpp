/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//runtime error, don't know why
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : m_head(head), e(time(0)) {
        while(head) {
            length++;
            head = head->next;
        }
        u = uniform_int_distribution<unsigned>(0, length-1);
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode *node = m_head;
        int n = u(e);
        while(n--) {
            node = node->next;
        }
        return node->val;
    }
    
private:
    ListNode *m_head;
    int length;
    uniform_int_distribution<unsigned> u;
    default_random_engine e;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

//Reservoir Sampling
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : m_head(head) {
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = m_head->val;
        ListNode* node = m_head->next;
        int i = 2;
        while(node) {
            int randomVal = rand() % i;
            if(randomVal == 0) 
                res = node->val;
            i++;
            node = node->next;
        }
        return res;
    }

private:
    ListNode* m_head;
};