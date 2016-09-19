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
ListNode* helper(ListNode* h, ListNode* head) {
	if (!h->next) { 
		head->next = h;
		return h;
	}
	ListNode *p = helper(h->next, head);
	p->next = h;
	return h;
}

ListNode* rotate(ListNode* head) {
	if (!head || !head->next)
		return head;
	ListNode* nh = new ListNode(0);
	helper(head, nh);
	head->next = NULL;
	return nh->next;
}

void reorderList(ListNode* head) {
	if (!head || !head->next)
		return ;
	ListNode* hh = new ListNode(0);
	hh->next = head;
	ListNode *p = hh, *q = hh;
	while (q->next) {
		p = p->next;
		q = q->next;
		if (!q->next) break;
		q = q->next;
	}
	q = p->next;
	p->next = NULL;
	ListNode *rh = rotate(q);
	bool f = 1;
	p = hh->next;
	q = hh;
	while (p || rh) {
		if (f) {
			q->next = p;
			p = p->next;
			q = q->next;
		}
		else {
			q->next = rh;
			rh = rh->next;
			q = q->next;
		}
		f = !f;
	}
}
};
