class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int x = 0, y = n;
        int m;
        while (x < y) {
            m = x + (y-x)/2;
            if (A[m] >= target) y = m;
            else x = m+1;
        }
        return x;
    }
};
