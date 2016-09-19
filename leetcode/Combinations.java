public class Solution {
		private List<List<Integer>> re;
	private List<Integer> l;
	private int ans[];
	
    public List<List<Integer>> combine(int n, int k) {
    	re = new ArrayList<List<Integer>>();
    	ans = new int[k];
        if (k == 0) return re;
        solve(n, k, 0);
        return re;
    }
    
    public void solve(int n, int k, int cur) {
    	if (n < 0) return ;
    	if (k == cur) {
    		l = new ArrayList<Integer>();
    		for (int i = k-1; i >= 0; --i) l.add(ans[i]);
    		re.add(l);
    		return ;
    	}
    	ans[cur] = n; solve(n-1, k, cur+1);
    	solve(n-1, k, cur);
    }
}
