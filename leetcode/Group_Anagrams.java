public class Solution {
	public List<String> anagrams(String[] strs) {
		String[] ss = new String[strs.length];
		System.arraycopy(strs, 0, ss, 0, ss.length);
		char[] cs = null;
		Map<String, List<String>> map = new HashMap<String, List<String>>();
		for (int i = 0; i < ss.length; ++i) {
			cs = ss[i].toCharArray();
			Arrays.sort(cs);
			if (map.containsKey(String.valueOf(cs)))
				map.get(String.valueOf(cs)).add(strs[i]);
			else {
				map.put(String.valueOf(cs), new ArrayList<String>());
				map.get(String.valueOf(cs)).add(strs[i]);
			}
		}
		List<String> ans = new ArrayList<String>();
		for (String s : map.keySet())
			if (map.get(s).size() > 1)
				ans.addAll(map.get(s));
		return ans;
	}
}
