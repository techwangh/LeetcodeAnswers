/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(!head) return NULL;
        RandomListNode* copyHead = new RandomListNode(head->label);
        RandomListNode *node = head->next, *pre = copyHead;
        while(node) {
        	pre->next = new RandomListNode(node->label);
        	pre = pre->next;
        	node = node->next;
        }
        node = head;
        RandomListNode* copyNode = copyHead;
        while(node) {
        	if(node->random) {
        		RandomListNode *tmpNode = head, *tmpCopyNode = copyHead;
        		while(node->random != tmpNode) {
        			tmpNode = tmpNode->next;
        			tmpCopyNode = tmpCopyNode->next;
        		}
        		copyNode->random = tmpCopyNode;
        	}
        	node = node->next;
        	copyNode = copyNode->next;
        }
        return copyHead;
    }
};

//hash table
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(!head) return NULL;
    	map<RandomListNode*, RandomListNode*> m;
        RandomListNode* copyHead = new RandomListNode(head->label);
        m[head] = copyHead;
        RandomListNode *node = head->next, *pre = copyHead;
        while(node) {
        	pre->next = new RandomListNode(node->label);
        	pre = pre->next;
        	node = node->next;
        }
        node = head;
        RandomListNode* copyNode = copyHead;
        while(node) {
        	copyNode->random = m[node->random];
        	node = node->next;
        	copyNode = copyNode->next;
        }
        return copyHead;
    }
};

//use no extra space
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(!head) return NULL;
  		RandomListNode* cur = head;
  		while(cur) {
  			RandomListNode* node = new RandomListNode(cur->label);
  			node->next = cur->next;
  			cur->next = node;
  			cur = node->next;
  		}
  		cur = head;
  		while(cur) {
  			if(cur->random) {
  				cur->next->random = cur->random->next;
  			}
  			cur = cur->next->next;
  		}
  		cur = head;
  		RandomListNode* res = head->next;
  		while(cur) {
  			RandomListNode* tmp = cur->next;
  			cur->next = tmp->next;
  			if(tmp->next) tmp->next = tmp->next->next;
  			cur = cur->next;
  		}
  		return res;
    }
};