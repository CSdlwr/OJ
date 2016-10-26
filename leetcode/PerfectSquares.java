
public class PerfectSquares {

    public static void main(String[] args) {
	PerfectSquares main = new PerfectSquares();
	System.out.println(main.numSquares(13));
    }

    public int numSquares(int n) {
	if (n <= 0) {
	    return 0;
	}
	int[] d = new int[n + 1];
	for (int i = 1; i <= Math.sqrt(n); ++i) {
	    d[i * i] = 1;
	}
	for (int i = 1; i <= n; ++i) {
	    if (d[i] != 0) {
		continue;
	    }
	    d[i] = n;
	    for (int j = 1; j <= i / 2; ++j) {
		int a = j;
		int b = i - a;
		if (d[a] + d[b] < d[i]) {
		    d[i] = d[a] + d[b];
		}
	    }
	}
	return d[n];
    }

}
