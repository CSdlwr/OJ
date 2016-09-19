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
	public ListNode mergeKLists(List<ListNode> lists) {
		int l = lists.size();
		if (lists == null || l == 0)
			return null;
		return solve(lists, 0, l);
	}
	
	public ListNode solve(List<ListNode> lists, int x, int y) {
		if (x >= y) return null;
		if (y-x == 1) return lists.get(x);
		int m = x + (y-x)/2;
		ListNode left = solve(lists, x, m);
		ListNode right = solve(lists, m, y);
		ListNode head = new ListNode(0);
		ListNode cur = head;
		while (right != null && left != null) {
			if (left.val > right.val) {
				cur.next = right;
				right = right.next;
				cur = cur.next;
			} else {
				cur.next = left;
				left = left.next;
				cur = cur.next;
			}
		}
		if (right == null) cur.next = left;
		if (left == null) cur.next = right;
		return head.next;
	}
}
