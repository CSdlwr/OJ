public class Solution {
    
	public boolean wordBreak(String s, Set<String> dict) {
		if (dict == null || dict.size() == 0) return false;
		if (s == null || s.length() == 0) return false;
		boolean vs[] = new boolean[256];
		for (int i = 0; i < vs.length; ++i)
			vs[i] = false;
		for (String str : dict) {
			for (int i = 0; i < str.length(); ++i) {
				if (!vs[str.charAt(i)]) 
					vs[str.charAt(i)] = true;
			}
		}
		for (int i = 0; i < s.length(); ++i)
			if (!vs[s.charAt(i)]) return false;
		return solve(s, dict);
	}
	
	public boolean solve(String s, Set<String> dict) {
		if (s.length() == 0) return true;
		for (String dt : dict) {
			if (s.startsWith(dt)) {
				String ns = s.substring(dt.length());
				if (solve(ns, dict)) return true;
			}
		}
		return false;
	}
}
