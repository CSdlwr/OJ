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
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
		if (headA == null || headB == null)
			return null;
		int la = 0, lb = 0;
		ListNode pa = headA;
		while (pa != null) {
			++la;
			pa = pa.next;
		}
		ListNode pb = headB;
		while (pb != null) {
			++lb;
			pb = pb.next;
		}
		int c = la-lb;
		int i = 0;
		pa = headA;
		pb = headB;
		if (c > 0) {
            while (i < c) {
    			pa = pa.next;
    			++i;
    		}
		} else {
		    c *= -1;
    		i = 0;
    		while (i < c) {
    			pb = pb.next;
    			++i;
    		}
		}
		while (pa != null) {
			if (pa == pb) return pa;
			pa = pa.next;
			pb = pb.next;
		}
		return null;
    }
}
