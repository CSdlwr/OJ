public class Solution {
	List<List<Integer>> rtn = null;
	int ans[], nm[];
	
	public List<List<Integer>> permuteUnique(int num[]) {
		rtn = new ArrayList<List<Integer>>();
		if (num == null || num.length == 0) return rtn;
		Arrays.sort(num);
		ans = new int[num.length]; nm = num;
		solve(0);
		return rtn;
	}

	public void solve(int cur) {
		if (cur == nm.length) {
			List<Integer> ls = new ArrayList<Integer>();
			for (int i = 0; i < cur; ++i) ls.add(ans[i]);
			rtn.add(ls); return ;
		}
		else for (int i = 0; i < nm.length; ++i) 
			if (i == 0 || nm[i] != nm[i-1]) {
			int c1 = 0, c2 = 0;
			for (int j = 0; j < cur; ++j) if (ans[j] == nm[i]) ++c1;
			for (int j = 0; j < nm.length; ++j) if (nm[j] == nm[i]) ++c2;
			if (c1 < c2) {
				ans[cur] = nm[i];
				solve(cur+1);
			}
		}
	}
}
