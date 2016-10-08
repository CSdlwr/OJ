/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null) {
            return head;
        }
        ListNode oddHead = head;
        ListNode evenHead = head.next;

        ListNode i = head;
        ListNode j = head.next;


        while (j != null) {
            i.next = j.next;
            i = j;
            j = j.next;
        }

        ListNode oddTail = findTail(oddHead);
        oddTail.next = evenHead;
        return oddHead;
    }
    
    private ListNode findTail(ListNode head) {
        if (head == null) {
            return head;
        }
        ListNode i = head;
        
        while (i.next != null) {
            i = i.next;
        }
        return i;
    }
}
