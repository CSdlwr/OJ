public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
		if (matrix == null) return false;
        int m = matrix.length;
        if (m == 0) return false;
        int n = matrix[0].length;
        if (n == 0) return false;
        int x = 0, y = m;
        int i = 0, j = n;
        int mid = 0, mmid = 0;
        while (x < y) {
        	mid = x + (y-x)/2;
        	if (matrix[mid][0] == target) return true;
        	else if (matrix[mid][0] > target) y = mid;
        	else if (matrix[mid][0] < target && matrix[mid][n-1] >= target) {
        		i = 0; j = n;
        		while (i < j) {
        			mmid = i + (j-i)/2;
        			if (matrix[mid][mmid] == target) return true;
        			else if (matrix[mid][mmid] > target) j = mmid;
        			else i = mmid+1;
        		}
        		return false;
        	}
        	else x = mid+1;
        }
        return false;
    }
}
