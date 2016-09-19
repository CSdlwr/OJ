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
    ListNode *swapPairs(ListNode *head) {
		if (head == NULL || head->next == NULL) return head;
    	ListNode *p = head, *q = p->next->next;
    	head = head->next;
    	while (1) {
    		p->next->next = p;
    		p->next = q;
    		if (q != NULL && q->next != NULL) {
    			p->next = q->next;
    			p = q; q = p->next->next;
    		}
    		else break;
    	}
    	return head;
    }
};
