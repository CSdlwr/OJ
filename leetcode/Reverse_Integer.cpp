class Solution {
public:
    int reverse(int x) {
        bool ng = 0;
		if (x < 0) { ng = 1; x *= -1; }
		int m = x, a = 0;
		while (m > 0) {
			a = a*10 + m%10;
			m /= 10;
		}
		if (ng) a *= -1;
		return a;
    }
};
