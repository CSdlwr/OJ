public class Solution {
    public boolean canPartition(int[] nums) {
        if (nums == null || nums.length == 0) {
            return false;
        }
        int sum = 0;
        int max = -1;
        for (int i : nums) {
            sum += i;
            if (max < i) {
                max = i;
            }
        }
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        if (max > target) {
            return false;
        }
        Arrays.sort(nums);
        return helper(nums, target, 0);
    }

    private boolean helper(int[] nums, int target, int start) {
        if (start >= nums.length || nums[start] > target) {
            return false;
        } else if (target == nums[start]) {
            return true;
        }
        return helper(nums, target - nums[start], start + 1) || helper(nums, target, start + 1);
    }
}
