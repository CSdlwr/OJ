public class Solution {
    public String minWindow(String S, String T) {
		String ans = "";
		int m = S.length(), n = T.length();
		if (n == 0 || m < n) return ans;
		Map<Character, Integer> dict = new HashMap<Character, Integer>();
		char[] as = S.toCharArray();
		char[] at = T.toCharArray();
		for (int i = 0; i < at.length; ++i) {
			if (!dict.containsKey(at[i]))
				dict.put(at[i], 1);
			else dict.put(at[i], dict.get(at[i])+1);
		}
		int cnt = 0;
		int i = 0, j = 0;
		int t = 0;
		int nn = dict.size();
		while (i <= m-n+1) {
			if(cnt < nn) {
				if (j >= m) break;
				if (dict.containsKey(as[j])) {
					t = dict.get(as[j]);
					dict.put(as[j], --t);
					if (t == 0) ++cnt;
				}
				++j;
				if (cnt == nn 
						&& (ans.length() == 0 || j-i < ans.length()))
					ans = S.substring(i, j);
			} else {
				if (dict.containsKey(as[i])) {
					t = dict.get(as[i]);
					dict.put(as[i], ++t);
					if (t == 1)	--cnt;
				}
				if (j-i < ans.length())
					ans = S.substring(i, j);
				++i;
			}
		}
		return ans;
    }
}
