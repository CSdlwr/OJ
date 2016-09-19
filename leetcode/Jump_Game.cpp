class Solution {
public:
    bool canJump(int A[], int n) {
    	if (n <= 1) return 1;
    	if (A[0] == 0) return 0;
    	int maxLen = A[0];
    	for (int i = 1; i < n; ++i) {
    		if (maxLen >= i && i+A[i] >= n-1)
    			return 1;
    		if (maxLen < i 
    			|| maxLen == i && A[i] == 0)
    			return 0;
    		if (A[i]+i > maxLen) maxLen = A[i]+i;
    	}
    	return 0;
    }
};
