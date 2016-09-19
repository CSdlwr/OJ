class Solution {
public:
    int getMax(int a, int b) {
    	return a > b ? a : b;
    }
    
    int getMin(int a, int b) {
    	return a > b ? b : a;
    }
    
    int maxProduct(int A[], int n) {
    	int B[n], C[n];
    	B[0] = C[0] = A[0];
    	for (int i = 1; i < n; ++i) {
    		if (A[i] < 0) {
    			B[i] = getMax(A[i], A[i]*C[i-1]);
    			C[i] = getMin(A[i], A[i]*B[i-1]);
    		} else {
    			B[i] = getMax(A[i], A[i]*B[i-1]);
    			C[i] = getMin(A[i], A[i]*C[i-1]);
    		}
    	}
    	int max = B[0];
    	for (int i = 1; i < n; ++i) 
    		if (B[i] > max) max = B[i];
    	return max;
    }
};
