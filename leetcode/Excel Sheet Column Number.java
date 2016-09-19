public class Solution {
	public int titleToNumber(String s) {
		String dict = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		int l = s.length()-1;
		int h = 1, ans = 0;
		for (int i = l; i >= 0; --i) {
			ans += h * (dict.indexOf(s.charAt(i)) + 1);
			h *= 26;
		}
		return ans;
	}
}
