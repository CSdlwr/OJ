public class Solution {
    public void moveZeroes(int[] nums) {
        if (nums == null) {
            return;
        }
        int cur = 0;
        int bound = 0;
        while (cur < nums.length) {
            if (nums[cur] != 0) {
                swap(nums, cur, bound);
                ++bound;
            }
            ++cur;
        }
    }

    public void swap(int[] nums, int x, int y) {
        int t = nums[x];
        nums[x] = nums[y];
        nums[y] = t;
    }
}
