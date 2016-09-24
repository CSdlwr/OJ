/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode hhead = new ListNode(0);
        hhead.next = head;

        ListNode current = head;
        ListNode next = current.next;

        while (next != null) {
            hhead.next = next;
            next = next.next;
            hhead.next.next = current;
            current = hhead.next;
        }
        head.next = null;
        return hhead.next;
    }
}
