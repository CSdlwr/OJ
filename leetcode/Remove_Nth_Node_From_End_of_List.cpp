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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	ListNode* hp = new ListNode(0);
    	hp->next = head;
    	ListNode *p = hp, *q = hp;
    	for (int i = 0; i < n; ++i) p = p->next;
    	while (p->next) {
    		p = p->next;
    		q = q->next;
    	}
    	if (q->next) {
    		ListNode *d = q->next;
    		q->next = d->next;
    		free(d);
    	}
    	return hp->next;
    }
};
