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
    ListNode* revert(ListNode *h, ListNode* &nh, int cur, int n, ListNode* &lr)  {
    	if (cur == n) {
    		nh = h;
    		lr = h->next;
    		return h;
    	}
    	ListNode *rh = revert(h->next, nh, cur+1, n, lr);
    	rh->next = h;
    	return h;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	ListNode *nh = new ListNode(0);
    	nh->next = head;
    	int i = 1;
    	ListNode *p = nh;
    	while (i < m) {
    		p = p->next;
    		++i;
    	}
    	ListNode *th = p->next;
    	ListNode *nwh = NULL, *lr = NULL;
    	revert(th, nwh, m, n, lr);
    	p->next = nwh;
    	th->next = lr;
    	return nh->next;
    }
};
