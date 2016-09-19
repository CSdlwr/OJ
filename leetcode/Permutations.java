public class Solution {
	
    private boolean vs[];
    
    private List<List<Integer>> re;
    
    private List<Integer> l;
    
    private int[] ans;
    
    public void solve(int cur, int[] num, int n, int ans[]) {
        if (cur == n) {
            l = new ArrayList<Integer>();
            for (int i = 0; i < n; ++i) l.add(ans[i]);
            re.add(l);
            return ;
        }
        for (int i = 0; i < n; ++i) if (!vs[i]) {
        	vs[i] = true; ans[cur] = num[i];
        	solve(cur+1, num, n, ans);
        	vs[i] = false;
        }
    }
    
    public List<List<Integer>> permute(int[] num) {
        int n = num.length;
        vs = new boolean[n];
        ans = new int[n];
        for (int i = 0; i < n; ++i) vs[i] = false;
        re = new ArrayList<List<Integer>>();
        l = new ArrayList<Integer>();
        solve(0, num, n, ans);
        return re;
    }
}
