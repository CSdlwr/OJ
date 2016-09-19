/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int ca = 0;
        ListNode l3 = new ListNode(0), p = l3;
        while (l1 != null || l2 != null || ca != 0) {
        	p.next = new ListNode(0);
        	if (l1 != null) { p.next.val += l1.val; l1 = l1.next; }
        	if (l2 != null) { p.next.val += l2.val; l2 = l2.next; }
        	p.next.val += ca;
        	ca = p.next.val / 10;
        	if (p.next.val > 9) p.next.val %= 10;
        	p = p.next;
        }
        return l3.next;
    }
}
