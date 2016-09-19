class Solution {
public:
    
    void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }
    
    int removeDuplicates(int A[], int n) {
        int j = 0, i = j-1;
        int mx = A[0]-1;
        while (j < n) {
            if (A[j] > mx) { mx = A[j]; swap(&A[++i], &A[j]); }
            ++j;
        }
        return i+1;
    }
};
