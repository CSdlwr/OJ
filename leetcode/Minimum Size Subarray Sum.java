public class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int i = 0;
        int j = 0;
        int ans = nums.length;
        int sum = 0;
        while (j < nums.length || sum >= s) {
            if (i > j) {
                ++j;
            } else {
                if (sum >= s) {
                    int len = j - i;
                    if (ans > len) {
                        ans = len;
                    }
                    sum -= nums[i++];
                } else {
                    sum += nums[j++];
                }
            }
        }
        if (ans == nums.length && (sum < s && i == 0 || i > 0 && sum + nums[0] < s)) {
            return 0;
        }
        return ans;
    }
}
