class Solution {
public:
    int solve(int x, int y) {
    	if (x >= y) return 1;
    	int sum = 0;
    	for (int i = x; i <= y; ++i) {
    		sum += solve(x, i-1) * solve(i+1, y);
    	}
    	return sum;
    }
    
    int numTrees(int n) {
    	return solve(1, n);
    }
};
