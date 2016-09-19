public class Solution {
	public List<String> wordBreak(String s, Set<String> dict) {
		List<String> tmp = new ArrayList<String>();
		List<String> ans = new ArrayList<String>();
		if (s == null || s.length() == 0)
			return ans;
		boolean vs[] = new boolean[256];
		for (String d : dict) {
			for (char ch : d.toCharArray()) 
				if (!vs[ch]) vs[ch] = true;
		}
		for (char ch : s.toCharArray())
			if (!vs[ch]) return ans;
		solve(tmp, s, dict, ans);
		return ans;
	}

	public void solve(List<String> tmp, String s, Set<String> dict,
			List<String> ans) {
		if (s == null || s.length() == 0) {
			StringBuilder sb = new StringBuilder(tmp.get(0));
			for (int i = 1; i < tmp.size(); ++i)
				sb.append(" ").append(tmp.get(i));
			ans.add(sb.toString());
			return ;
		}
		for (String d : dict) {
			if (s.startsWith(d)) {
				tmp.add(d);
				solve(tmp, s.substring(d.length()), dict, ans);
				tmp.remove(tmp.size()-1);
			}
		}
	}
}
