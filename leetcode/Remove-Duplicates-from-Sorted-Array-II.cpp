class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if (n <= 2) return n;
    	int cnt = 1, len = 1;
    	for (int i = 1; i < n; ++i) {
    		if (A[i] == A[i-1] && cnt < 2) {
    			++cnt; A[len++] = A[i];
    		}
    		else if (A[i] != A[i-1]) {
    			cnt = 1;
    			A[len++] = A[i];
    		}
    	}
    	return len;
    }
};
