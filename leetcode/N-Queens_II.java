public class Solution {
	int nn = 0;
	int ans = 0;
	Set<Integer> v1 = new HashSet<Integer>();
	Set<Integer> v2 = new HashSet<Integer>();
	Set<Integer> v3 = new HashSet<Integer>();
	
	public int totalNQueens(int n) {
		nn = n;
		solve(0, n);
		return ans;
	}
	
	public void solve(int cur, int l) {
		if (l == 0) {
			++ans;
			return ;
		}
		for (int i = 0; i < nn; ++i) {
			if (!v1.contains(i) && !v2.contains(cur+i) 
					&& !v3.contains(cur-i)) {
				v1.add(i);
				v2.add(cur+i);
				v3.add(cur-i);
				solve(cur+1, l-1);
				v1.remove(i);
				v2.remove(cur+i);
				v3.remove(cur-i);
			}
		}
	}
}
