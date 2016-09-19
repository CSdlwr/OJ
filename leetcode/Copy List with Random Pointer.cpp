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
    	if (!head) return NULL;
    	RandomListNode *p = head;
    	RandomListNode *q = NULL;
    	while (p) {
    		q = new RandomListNode(p->label);
    		q->next = p->next;
    		q->random = p->random;
    		p->next = q;
    		p = q->next;
    	}
    	p = head;
    	q = p->next;
    	while (q) {
    		if (q->random)
    			q->random = q->random->next;
    		if (!q->next) break;
    		q = q->next->next;
    	}
    	RandomListNode *h = head->next;
    	q = h;
    	p = head;
    	while (q) {
    		p->next = q->next;
    		p = q;
    		q = q->next;
    	}
    	return h;
    }
};
