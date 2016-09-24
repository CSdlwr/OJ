public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> s1 = new HashSet<Integer>(nums1.length);
        Set<Integer> s2 = new HashSet<Integer>(nums2.length);
        for (int i : nums1) {
            s1.add(i);
        }
        int[] ans = new int[nums2.length];
        int cnt = 0;
        for (int i : nums2) {
            if (s1.contains(i) && !s2.contains(i)) {
                s2.add(i);
                ans[cnt++] = i;
            }
        }
        return Arrays.copyOfRange(ans, 0, cnt);
    }
}
