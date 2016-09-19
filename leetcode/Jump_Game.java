public class Solution {
    public boolean canJump(int[] A) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(A.length <= 1)
			return true;
		if(A[0] >= (A.length - 1))
			return true;
		int maxlength = A[0];
		if(maxlength == 0)
		    return false;
		for(int i = 1; i < A.length - 1; i++)
		{
			if(maxlength >= i && (i + A[i]) >= A.length - 1)
				return true;
			if(maxlength < i || maxlength == i && A[i] == 0)
				return false;
			if((i + A[i]) > maxlength)
				maxlength = i + A[i];
		}
		return false;
    }
}
