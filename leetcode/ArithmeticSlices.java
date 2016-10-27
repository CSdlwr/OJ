
public class ArithmeticSlices {

    public static void main(String[] args) {
	ArithmeticSlices main = new ArithmeticSlices();
	System.out.println(main.numberOfArithmeticSlices(new int[] {1,1,3,5,8}));
    }
    
    public int numberOfArithmeticSlices(int[] A) {
	if (A == null || A.length < 3) {
	    return 0;
	}
	int sum = 0;
	int[] d = new int[A.length];
	if (A[1] - A[0] == A[2] - A[1]) {
	    d[2] = 1;
	}
	sum += d[2];
	for (int i = 3; i < A.length; ++i) {
	    if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
		d[i] = d[i - 1] + 1;
	    } else {
		d[i] = 0;
	    }
	    sum += d[i];
	}
	return sum;
    }
}
