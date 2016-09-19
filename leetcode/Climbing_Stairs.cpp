class Solution {
public:
    int solve(int n, int d[]) {
        if (n == 1) return d[1] = 1;
    	if (n == 2) return d[2] = 2;
    	if(d[n] != 0) return d[n];
    	if (d[n-2] == 0) d[n-2] = solve(n-2, d);
    	if (d[n-1] == 0) d[n-1] = solve(n-1, d);
    	return d[n] = d[n-1]+d[n-2];
    }
    
    int climbStairs(int n) {
    	int d[100];
        memset(d, 0, sizeof(d));
        return solve(n, d);
    }
};
