
public class CountNumbersWithUniqueDigits {

    public static void main(String[] args) {
	CountNumbersWithUniqueDigits main = new CountNumbersWithUniqueDigits();
	System.out.println(main.countNumbersWithUniqueDigits(2));
	System.out.println(main.countNumbersWithUniqueDigits(3));
	System.out.println(main.countNumbersWithUniqueDigits(4));
    }

    public int countNumbersWithUniqueDigits(int n) {
	if (n == 0) {
	    return 0;
	}
	int[] d = new int[n + 1];
	d[1] = 10;
	for(int i = 2; i <= n; ++i) {
	    int count = 9;
	    for (int j = 1; j < i; ++j) {
		count *= (10 - j);
	    }
	    d[i] = d[i - 1] + count;
	    //System.out.printf("%d, %d, %d, %d\n", i, d[i], d[i - 1], count);
	}
	return d[n];
    }

}
