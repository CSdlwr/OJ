
public class UniquePaths {

    private int rowLength;
    private int columnLength;
    private int d[][];

    public static void main(String[] args) {
	UniquePaths main = new UniquePaths();
	System.out.println(main.uniquePaths(100, 100));
    }

    public int uniquePaths(int m, int n) {
	if (m < 0 || n < 0) {
	    return 0;
	}
	if (m == 0 || n == 0) {
	    return 1;
	}
	rowLength = m;
	columnLength = n;
	d = new int[rowLength][columnLength];
	return finder(0, 0);
    }

    private int finder(int x, int y) {
	if (x >= rowLength || y >= columnLength) {
	    return 0;
	}
	if (x == rowLength - 1 && y == columnLength - 1) {
	    d[x][y] = 1;
	}
	if (d[x][y] > 0) {
	    return d[x][y];
	}
	d[x][y] = finder(x + 1, y) + finder(x, y + 1);
	return d[x][y];
    }
}
