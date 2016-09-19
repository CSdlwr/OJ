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
ListNode* mergeSort(ListNode* head) {
	if (!head || !head->next) return head;
	ListNode *f = head, *s = head;
	while (1) {
		f = f->next;
		if (!f) break;
		f = f->next;
		if (!f) break;
		s = s->next;
	}
	ListNode* rh = s->next;
	s->next = NULL;
	ListNode* l = mergeSort(head);
	ListNode* r = mergeSort(rh);
	if (!l) return r;
	if (!r) return l;
	ListNode* helper = NULL;
	if (l->val < r->val) {
		helper = l;
		l = l->next;
	}
	else {
		helper = r;
		r = r->next;
	}
	ListNode* cur = helper;
	while (l && r) {
		if (l->val < r->val) {
			cur->next = l;
			l = l->next;
			cur = cur->next;
		}
		else {
			cur->next = r;
			r = r->next;
			cur = cur->next;
		}
	}
	if (!l) cur->next = r;
	else cur->next = l;
	return helper;
}

ListNode* sortList(ListNode* head) {
	if (!head || !head->next) return head;
//	ListNode* t = head;
//	while (t->next) t = t->next;
	head = mergeSort(head);
	return head;
}
};
