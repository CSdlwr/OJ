public class Solution {
	public int sqrt(int x) {
		if (x == 0 || x == 1)
			return x;
		double l = 0, h = x;
		double m = l+(h-l)/2;
		while (Math.abs(m*m-x) > 0.00001) {
			if (m*m > x)
				h = m;
			else 
				l = m;
			m = l+(h-l)/2;
		}
		return (int) m;
	}
}
