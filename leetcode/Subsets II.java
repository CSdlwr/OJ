public class Solution {
	List<List<Integer>> rtn = null;
	int nm[];
	int ans[];
	
	public List<List<Integer>> subsetsWithDup(int[] num) {
		rtn = new ArrayList<List<Integer>>();
		if (num == null || num.length == 0) return rtn;
		nm = num; ans = new int[nm.length];
		Arrays.sort(num); solve(0, 0);
		rtn.add(new ArrayList<Integer>());
		return rtn;
	}
	
	public void solve(int acur, int ccur) {
		if (ccur == nm.length) return ;
		ans[acur] = nm[ccur];
		List<Integer> ls = new ArrayList<Integer>();
		for (int i = 0; i < acur+1; ++i) ls.add(ans[i]);
		rtn.add(ls);
		solve(acur+1, ccur+1);
		int i = ccur+1;
		while (i < nm.length && nm[i] == nm[i-1]) ++i;
		solve(acur, i);
	}
}
