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
    ListNode *rotateRight(ListNode *head, int k) {
        int len = 0;
        ListNode* p = head;
        while (p != NULL) { ++len; p = p->next; }
        if (len == 0) return head;
        if (k%len == 0) return head;
        k %= len; p = head;
        int i = 1;
        while (i < len-k) { ++i; p = p->next; }
        ListNode* q = p->next;
        p->next = NULL;
        p = q;
        while (q->next != NULL) q = q->next;
        q->next = head; head = p;
        return head;
    }
};
