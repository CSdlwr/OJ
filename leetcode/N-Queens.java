public class Solution {
	int nn = 0;
	String[] ss = null;
	int ii[] = null;
	Set<Integer> v1 = new HashSet<Integer>();
	Set<Integer> v2 = new HashSet<Integer>();
	Set<Integer> v3 = new HashSet<Integer>();
	List<String[]> ans = new ArrayList<String[]>();
	
	public List<String[]> solveNQueens(int n) {
		nn = n;
		ii = new int[nn];
		ss = new String[nn];
		solve(0, nn);
		return ans;
	}
	
	public void solve(int cur, int l) {
		if (l == 0) {
			char chs[] = new char[nn];
			for (int i = 0; i < nn; ++i) {
				for (int j = 0; j < nn; ++j) {
					if (j == ii[i]) 
						chs[j] = 'Q';
					else 
						chs[j] = '.';
				}
				ss[i] = String.valueOf(chs);
			}
			ans.add(ss);
			ss = new String[nn];
			return ;
		}
		for (int i = 0; i < nn; ++i) {
			if (!v1.contains(i) && !v2.contains(cur+i) 
					&& !v3.contains(cur-i)) {
				v1.add(i);
				v2.add(cur+i);
				v3.add(cur-i);
				ii[cur] = i;
				solve(cur+1, l-1);
				v1.remove(i);
				v2.remove(cur+i);
				v3.remove(cur-i);
			}
		}
	}
}
