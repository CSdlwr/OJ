public class Solution {
	List<List<Integer>> rtn;
	List<Integer> ls;
	int ans[];
	int can[];
	
	public List<List<Integer>> combinationSum(int[] candidates, int target) {
		rtn = new ArrayList<List<Integer>>();
		ans = new int[1000]; can = candidates;
		Arrays.sort(candidates);
		solve(0, 0, target);
		return rtn;
	}
	
	public void solve(int ccnt, int acnt, int tar) {
		if (tar < 0) return ;
		if (tar == 0) {
			ls = new ArrayList<Integer>();
			for (int i = 0; i < acnt; ++i) ls.add(ans[i]);
			rtn.add(ls); return ;
		}
		if (ccnt >= can.length) return ;
		ans[acnt] = can[ccnt];
		solve(ccnt, acnt+1, tar-can[ccnt]);
		solve(ccnt+1, acnt, tar);
	}
}
