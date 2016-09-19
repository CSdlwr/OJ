public class Solution {
	public String countAndSay(int n) {
		int cnt = 0;
		String s = "1";
		while (cnt < n-1) {
			s = say(s);
			++cnt;
		}
		return s;
	}
	
	public String say(String s) {
		StringBuilder sb = new StringBuilder();
		int i = 0, n = 1;
		while (i < s.length()) {
			if (i+1 < s.length()) {
				if (s.charAt(i+1) == s.charAt(i)) ++n;
				else {
					sb.append(n);
					sb.append(s.charAt(i));
					n = 1;
				}
			} else {
				sb.append(n);
				sb.append(s.charAt(i));
				break;
			}
			++i;
		}
		return sb.toString();
	}
}
