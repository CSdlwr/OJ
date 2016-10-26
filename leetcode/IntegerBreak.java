
public class IntegerBreak {

    public static void main(String[] args) {
	IntegerBreak main = new IntegerBreak();
	System.out.println(main.integerBreak(1));
	System.out.println(main.integerBreak(2));
	System.out.println(main.integerBreak(3));
	System.out.println(main.integerBreak(4));
	System.out.println(main.integerBreak(5));
	System.out.println(main.integerBreak(6));
	System.out.println(main.integerBreak(7));
	System.out.println(main.integerBreak(8));
	System.out.println(main.integerBreak(9));
	System.out.println(main.integerBreak(10));
    }

    public int integerBreak(int n) {
	if (n == 0 || n == 1) {
	    return 0;
	}
	if (n == 2) {
	    return 1;
	}
	int[] d = new int[n + 1];
	d[1] = 0;
	d[2] = 1;
	d[3] = 2;
	for (int i = 4; i <= n; ++i) {
	    int t = 0;
	    for (int j = 1; j <= i / 2; ++j) {
		int a = d[j] > j ? d[j] : j;
		int b = i - j;
		b = d[b] > b ? d[b] : b;
		int tt = a * b;
		if (t < tt) {
		    t = tt;
		}
	    }
	    d[i] = t;
	}
	return d[n];
    }
}
