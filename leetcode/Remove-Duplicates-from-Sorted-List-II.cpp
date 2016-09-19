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
    ListNode *deleteDuplicates(ListNode *head) {
	if (head == NULL || head->next == NULL) return head;
	ListNode *h = (ListNode*) malloc(sizeof(ListNode));
	h->next = head;
	ListNode *p = h, *q = head;
	while (q && q->next) {
		if (q->val == q->next->val) {
			while (q->next && q->val == q->next->val) q = q->next;
			p->next = q->next; q = q->next;
		}
		else {
			p = q; q = q->next;
		}
	}
	head = h->next;
	free(h);
	return head;
    }
};
