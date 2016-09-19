class Solution {
    public:
    void swap(int *a, int* b) {
	    int t = *a; *a = *b; *b = t;
    }

    int removeElement(int A[], int n, int elem) {
	    int j = 0, i = j-1;
	    while (j < n) {
		    if (A[j] != elem) swap(&A[++i], &A[j]);
		    ++j;
	    }
	    return i+1;
    }
};
