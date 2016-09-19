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
    ListNode *partition(ListNode *head, int x) {
    	if (!head) return head;
    	ListNode *cur = head;
    	ListNode *sh = new ListNode(0);
    	ListNode *bh = new ListNode(0);
    	ListNode *s = sh, *b = bh;
    	while (cur) {
    		if (cur->val < x) {
    			s->next = cur; cur = cur->next; 
    			s = s->next; s->next = NULL;
    		}
    		else {
    			b->next = cur; cur = cur->next;
    			b = b->next; b->next = NULL;
    		}
    	}
    	s->next = bh->next;
    	free(bh);
    	head = sh->next; 
    	free(sh);
    	return head;
    }
};
