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
    bool hasCycle(ListNode *head) {
    	if (head == NULL) return 0;
    	ListNode *s = head, *f = head;
    	while (1) {
    		f = f->next;
    		if (f == NULL) return 0;
    		f = f->next; 
    		if (f == NULL) return 0;
    		s = s->next;
    		if (s == f) return 1;
    	}
    }
};
