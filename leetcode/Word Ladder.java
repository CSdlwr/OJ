public class Solution {
	Set<String> vs = null;
	
	public boolean check(String a, String b) {
		int cnt = 0;
		for (int i = 0; i < a.length(); ++i) {
			if (a.charAt(i) != b.charAt(i) && ++cnt > 1)
				return false;
		}
		return true;
	}
	
	public int ladderLength(String start, String end, Set<String> dict) {
		vs = new HashSet<String>();
		Queue<String> que = new LinkedList<String>();
		Map<String, String> pre = new HashMap<String, String>();
		que.add(start);
		vs.add(start);
		pre.put(start, null);
		String cur = null;
		while (!que.isEmpty()) {
			cur = que.poll();
			if (check(cur, end)) {
				pre.put(end, cur);
				break;
			}
			for (int i = 0; i < cur.length(); ++i) {
				for (char j = 'a'; j <= 'z'; ++j) {
					char[] chs = cur.toCharArray();
					if (j == chs[i])
						continue;
					chs[i] = j;
					String ts = String.valueOf(chs);
					if (dict.contains(ts) && !vs.contains(ts)) {
						pre.put(ts, cur);
						vs.add(ts);
						que.add(ts);
					}
				}
			}
			/*for (String s : dict) {
				if (!vs.contains(s) && check(cur, s)) {
					pre.put(s, cur);
					vs.add(s);
					que.add(s);
				}
			}*/
		}
		int ans = 0;
		cur = end;
		if (!pre.containsKey(end))
			return 0;
		while (cur != null) {
			++ans;
			cur = pre.get(cur);
		}
		return ans;
	}
}
