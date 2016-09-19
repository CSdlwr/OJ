public class Solution {
	List<List<String>> rtn = null;
	List<String> ls = null;
	String[] ans;
	
	public List<List<String>> partition(String s) {
		rtn = new ArrayList<List<String>>();
		if (s == null || s.length() == 0) return rtn;
		ls = new ArrayList<String>();
		char[] arr = s.toCharArray();
		ans = new String[s.length()];
		solve(arr, 0, 0);
		return rtn;
	}
	
	public void solve(char[] s, int x, int dep) {
		if (x == s.length) {
			ls = new ArrayList<String>();
			for (int i = 0; i < dep; ++i) ls.add(ans[i]);
			rtn.add(ls); return ;
		}
		for (int i = x; i < s.length; ++i) {
			if (check(s, x, i)) {
				ans[dep] = String.valueOf(s).substring(x, i+1);
				solve(s, i+1, dep+1);
			}
		}
	}
	
	public boolean check(char[] s, int x, int y) {
		int i = x, j = y;
		while (i < j) {
			if (s[i] != s[j]) return false;
			++i; --j;
		}
		return true;
	}
}
