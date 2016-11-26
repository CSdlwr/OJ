import java.util.Arrays;

public class LongestPalindrome {
    public int longestPalindrome(String s) {
	int[] counts = new int[256];
	for (char c : s.toCharArray()) {
	    counts[c] += 1;
	}

	int ans = 0;
	Arrays.sort(counts);
	boolean hasOdd = false;
	for (int i : counts) {
	    if (i % 2 == 0) {
		ans += i;
	    } else {
		ans += i - 1;
		hasOdd = true;
	    }
	}
	if (hasOdd) {
	    ans += 1;
	}
	return ans;
    }
}
