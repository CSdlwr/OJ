class Solution {
public:
    bool isPalindrome(int x) {
        	if (x < 0) return 0;
    	int m = x, y = 0;
    	while (m > 0) {
    		y = y*10+m%10;
    		m /= 10;
    	}
    	if (y == x) return true;
    	return false;
    }
};
