public class Solution {
    public int findPeakElement(int[] num) {
        int p = 0, m = num[0];
        for (int i = 1; i < num.length; ++i) {
            if (num[i] > m) {
                p = i;
                m = num[i];
            }
        }
        return p;
    }
}
