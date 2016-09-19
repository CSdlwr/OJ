public class Solution {
    public int lengthOfLongestSubstring(String s) {
    	if (s == null) return 0;
    	boolean vs[] = new boolean[256];
    	for (int i = 0; i < 256; ++i) vs[i] = false;
        int cnt = 0;
        char arr[] = s.toCharArray();
        int len = arr.length;
        int i = 0, j = i;
        while (j < len) {
        	if (!vs[arr[j]]) {
        	    cnt = cnt < j-i+1 ? j-i+1 : cnt;
        	    vs[arr[j++]] =  true;
        	}
        	else vs[arr[i++]] = false;
        }
        return cnt;
    }
}
