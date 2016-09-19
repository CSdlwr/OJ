public class Solution {
	char[] arr = null;
	int[] d = null;
	
	public int numDecodings(String s) {
		if (s == null || s.length() == 0) 
			return 0;
		arr = s.toCharArray();
		if (arr[0] == '0') return 0;
		for (int i = 1; i < arr.length; ++i)
			if (arr[i] == '0' && arr[i-1] != '1' && arr[i-1] != '2') 
			    return 0;
		d = new int[arr.length];
		for (int i = 0; i < d.length; ++i)
			d[i] = -1;
		solve(arr.length-1);
		return d[arr.length-1];
	}
	
	public int solve(int n) {
		if (n < 0) return 1;
		if (d[n] != -1) return d[n];
		if (n == 0) return d[0] = 1;
		if (arr[n] == '0') return d[n] = solve(n-2);
		d[n] = solve(n-1);
		int num = (arr[n-1]-'0')*10+arr[n]-'0';
		if (arr[n-1] == '0' || num > 26) return d[n];
		return d[n] += solve(n-2);
	}
}
