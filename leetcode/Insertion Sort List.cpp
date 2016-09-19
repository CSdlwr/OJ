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
    ListNode *insertionSortList(ListNode *head) {
    	if (!head) return head;
    	ListNode* helper = new ListNode(0);
    	ListNode* cur = head;
    	while (cur) {
    		ListNode* cn = cur->next;
    		ListNode* pre = helper;
    		while (pre->next && pre->next->val <= cur->val)
    			pre = pre->next;
    		cur->next = pre->next;
    		pre->next = cur;
    		cur = cn;
    	}
    	return helper->next;
    }
};
