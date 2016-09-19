class Solution {
public:
    int getMax(int a, int b) {
    	return a > b ? a : b;
    }
    
    int getMin(int a, int b) {
    	return a > b ? b : a;
    }
    
    int trap(int A[], int n) {
    	int ans = 0;
    	if (n == 0) return ans;
    	int left[n], right[n];
    	left[0] = 0;
    	for (int i = 1; i < n; ++i) 
    		left[i] = getMax(left[i-1], A[i-1]);
    	right[n-1] = 0;
    	for (int i = n-2; i >= 0; --i)
    		right[i] = getMax(right[i+1], A[i+1]);
    	int t = 0;
    	for (int i = 0; i < n; ++i) {
    		if ((t = getMin(left[i], right[i])) > A[i])
    			ans += t - A[i];
    	}
    	return ans;
    }
};
