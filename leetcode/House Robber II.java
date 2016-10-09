public class Solution {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int[] maxValue = new int[nums.length];
        for (int i = 0; i < maxValue.length; ++i) {
            maxValue[i] = -1;
        }
        maxValue[maxValue.length - 1] = 0;
        int choose0 = nums[0] + find(nums, 2, maxValue);
        for (int i = 0; i < maxValue.length; ++i) {
            maxValue[i] = -1;
        }
        int notChoose0 = find(nums, 1, maxValue);
        return Math.max(choose0, notChoose0);
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
