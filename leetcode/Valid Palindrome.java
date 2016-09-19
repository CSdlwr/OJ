public class Solution {
    public boolean isPalindrome(String s) {
        char arr[] = new char[s.length()];
		int cnt = 0; 
		char c = 0;
		s = s.toLowerCase();
		for (int i = 0; i < s.length(); ++i) {
			c = s.charAt(i);
			if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9') arr[cnt++] = c;
		}
		int i = 0, j = cnt - 1;
		while (i < j) if (arr[i++] != arr[j--]) return false;
		return true;
    }
}
