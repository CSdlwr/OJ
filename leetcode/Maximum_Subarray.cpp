class Solution {
public:
    int maxSubArray(int A[], int n) {
        int B[n]; B[0] = A[0];
    	int max = B[0];
    	for (int i = 1; i < n; ++i) {
    		if (B[i-1] > 0) B[i] = B[i-1]+A[i];
    		else B[i] = A[i];
    		if (B[i] > max) max = B[i];
    	}
    	return max;
    }
};
