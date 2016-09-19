public class Solution {
	List<String> ans = null;
	
	public List<String> restoreIpAddresses(String s) {
		ans = new ArrayList<String>();
		char[] chs = new char[s.length()+3];
		solve(0, 0, chs, s);
		return ans;
	}
	
	public void solve(int cur, int x, char[] chs, String s) {
		for (int i = 0; i < 3; ++i) {
			if (x+i < s.length()) {
				if (cur < 3) {
					String sn = s.substring(x, x+i+1);
					if (Integer.parseInt(sn) > 255)
						break;
					chs[cur+x+i] = s.charAt(x+i);
					chs[cur+x+i+1] = '.';
					solve(cur+1, x+i+1, chs, s);
				} else {
					String s3 = s.substring(x, s.length());
					if (s3.charAt(0) == '0' && s3.length() == 1 
							|| s3.length() > 0 && s3.length() < 4 && s3.charAt(0) != '0'
								&& Integer.parseInt(s3) <= 255) {
						for (int j = 0; j < s3.length(); ++j)
							chs[x+cur+j] = s3.charAt(j);
						ans.add(String.valueOf(chs));
						break;
					}
				}
			}
			if (x < s.length() && s.charAt(x) == '0')
				break;
		}
	}
}
