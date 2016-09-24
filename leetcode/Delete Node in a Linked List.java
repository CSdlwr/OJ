/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void deleteNode(ListNode node) {
        if (node == null) {
            return;
        }
        
        ListNode current = node;
        ListNode next = node.next;
        
        while (next != null) {
            current.val = next.val;
            if (next.next == null) {
                current.next = null;
                break;
            }
            current = next;
            next = next.next;
        }        
    }
}
