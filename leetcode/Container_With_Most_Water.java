public class Solution {
    public int maxArea(int[] height) {
		int mv = 0, t = 0;;
		int i = 0, j = height.length-1;
		while (i < j) {
			if (height[i] <= height[j]) {
				t = height[i] * (j-i);
				mv = mv < t ? t : mv;
				++i;
			}
			else {
				t = height[j] * (j-i);
				mv = mv < t ? t : mv;
				--j;
			}
		}
		return mv;
    }
}
