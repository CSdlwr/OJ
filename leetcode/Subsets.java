public class Solution {
	List<List<Integer>> rtn = null;
	List<Integer> ls = null;
	int ans[];
	int s[];
	int len;
	
	public List<List<Integer>> subsets(int[] S) {
        rtn = new ArrayList<List<Integer>>();
		if (S == null || S.length == 0) return rtn;
		len = S.length; s = S;
		Arrays.sort(s);
		ans = new int[len];
		solve(0, 0);
		rtn.add(new ArrayList<Integer>());
// 		Comparator<List<Integer>> comp = new Comparator<List<Integer>>() {
			
// 			@Override
// 			public int compare(List<Integer> o1, List<Integer> o2) {
// 				// TODO Auto-generated method stub
// 				if (o1.size() < o2.size()) return -1;
// 				else if (o1.size() > o2.size()) return 1;
// 				return 0;
// 			}
// 		};
// 		Collections.sort(rtn, comp);
		return rtn;
	}
	
	public void solve(int acur, int ccur) {
		if (ccur >= len) return ;
		ans[acur] = s[ccur];
		ls = new ArrayList<Integer>();
		for (int i = 0; i < acur+1; ++i) ls.add(ans[i]);
		rtn.add(ls);
		solve(acur+1, ccur+1);
		solve(acur, ccur+1);
	}
}
