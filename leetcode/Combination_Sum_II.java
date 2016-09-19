public class Solution {
	List<List<Integer>> rtn;
	List<Integer> ls;
	int[] n;
	int[] ans;
	
	public void solve(int acnt, int ccnt, int tar) {
		if (tar < 0) return ;
		if (tar == 0) {
			for (List<Integer> rl : rtn) {
				boolean fg = true;
				if (acnt == rl.size()) {
					for (int j = 0; j < acnt; ++j) 
						if (ans[j] != rl.get(j)) { fg = false; break; }
				    if (fg) return ;
				}
			}
			ls = new ArrayList<Integer>();
			for (int i = 0; i < acnt; ++i) ls.add(ans[i]);
			rtn.add(ls); return ;
		}
		if (ccnt >= n.length) return ;
		ans[acnt] = n[ccnt];
		solve(acnt+1, ccnt+1, tar-n[ccnt]);
		solve(acnt, ccnt+1, tar);
	}
	
    public List<List<Integer>> combinationSum2(int[] num, int target) {
        rtn = new ArrayList<List<Integer>>();
        ans = new int[num.length]; n = num;
        Arrays.sort(num);
        solve(0, 0, target);
        return rtn;
    }
}
