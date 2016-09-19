class Solution {
    public:

    int mm, nn;

    int solve(int m, int n, long long d[][100]) {
	    if (m == mm && n == nn) return d[m][n] = 1;
	    if (m > mm || n > nn) return 0;
	    if (d[m][n] != -1) return d[m][n];
	    ++d[m][n];
	    d[m][n] += solve(m+1, n, d);
	    d[m][n] += solve(m, n+1, d);
	    return d[m][n];
    }

    int uniquePaths(int m, int n) {
	    mm = m-1; nn = n-1;
	    long long d[100][100];
	    for (int i = 0; i < m; ++i)
	    for (int j = 0; j < n; ++j) d[i][j] = -1;
	    solve(0, 0, d);
	    return d[0][0];
    }
};
