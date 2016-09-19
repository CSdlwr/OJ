public class Solution {
	
    List<String> ans = null;
    int nn;

    public List<String> generateParenthesis(int n) {
	    nn = n;
	    char[] chs = new char[n*2];
	    ans = new ArrayList<String>();
	    solve(0, 0, 0, chs);
	    return ans;
    }

    public void solve(int x, int y, int cur, char[] chs) {
	    if (x == nn && y == nn) {
		    ans.add(String.valueOf(chs));
		    return ;
	    }
	    if (x == nn) {
		    chs[cur] = ')';
		    solve(x, y+1, cur+1, chs);
	    } else if (x == y) {
		    chs[cur] = '(';
		    solve(x+1, y, cur+1, chs);
	    } else {
		    chs[cur] = '(';
		    solve(x+1, y, cur+1, chs);
		    chs[cur] = ')';
		    solve(x, y+1, cur+1, chs);
	    }
    }
}
