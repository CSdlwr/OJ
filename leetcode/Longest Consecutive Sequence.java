public class Solution {
    public int longestConsecutive(int[] num) {
		if (num == null || num.length == 0)
			return 0;
		int ans = 1;
		Set<Integer> dict = new HashSet<Integer>();
		for (Integer i : num)
			if (!dict.contains(i))
				dict.add(i);
		int cnt = 1;
		int left = 0, right = 0;
		for (Integer i : num) {
			left = i-1;
			right = i+1;
			cnt = 1;
			while (dict.contains(left)) {
				++cnt;
				dict.remove(left);
				--left;
			}
			while (dict.contains(right)) {
				++cnt;
				dict.remove(right);
				++right;
			}
			ans = ans < cnt ? cnt : ans;
		}
		return ans;
    }
}
