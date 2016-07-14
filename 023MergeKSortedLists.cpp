/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Divide and conquer
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if(lists.size() == 0) return NULL;
    	int n = lists.size();
    	while(n > 1) {
			int k = (n+1)/2;
    		for(int i = 0; i < n/2; ++i) {
    			lists[i] = mergeTwoLists(lists[i], lists[i+k]);
    		}
    		n = k;
    	}
    	return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode dummy(0);
    	ListNode* tail = &dummy;
    	while(l1 && l2) {
    		if(l1->val < l2->val) {
    			tail->next = l1;
    			l1 = l1->next;
    		}else {
    			tail->next = l2;
    			l2 = l2->next;
    		}
    		tail = tail->next;
    	}
    	tail->next = l1 ? l1 : l2;
    	return dummy.next;
    }    
};


//use priority_queue
struct cmp
{
	bool operator() (ListNode* l1, ListNode* l2) {
		return l1->val > l2->val;
	}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
  		priority_queue<ListNode*, vector<ListNode*>, cmp> q;
  		for(ListNode* node : lists) {
  			if(node) q.push(node);
  		}

  		ListNode dummy(-1);
  		ListNode* tail = &dummy;
  		while(!q.empty()) {
  			ListNode* tmp = q.top();
  			tail->next = tmp;
  			q.pop();
  			if(tmp->next) q.push(tmp->next);
  			tail = tail->next;
  		}
  		return dummy.next;
    }
};