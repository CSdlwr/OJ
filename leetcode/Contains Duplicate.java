public class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> s = new HashSet<Integer>(nums.length);
        for (int i : nums) {
            s.add(i);
        }
        return s.size() != nums.length;
    }
}
