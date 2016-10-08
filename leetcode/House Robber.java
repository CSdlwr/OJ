public class Solution {
    public int rob(int[] nums) {
        int[] maxValue = new int[nums.length];
        for (int i = 0; i < nums.length; ++i) {
            maxValue[i] = -1;
        }
        return find(nums, 0, maxValue);
    }

    public int find(int[] nums, int index, int[] maxValue) {
        if (index >= nums.length) {
            return 0;
        }
        if (maxValue[index] >= 0) {
            return maxValue[index];
        }
        int choose = nums[index] + find(nums, index + 2, maxValue);
        int notChoose = find(nums, index + 1, maxValue);
        maxValue[index] = Math.max(choose, notChoose);
        return maxValue[index];
    }
}
