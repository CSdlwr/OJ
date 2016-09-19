public class Solution {
    
	public void revert(char[] arr, int i, int j) {
		char ch;
		while (i < j) {
			ch = arr[i]; arr[i] = arr[j]; arr[j] = ch;
			++i; --j;
		}
	}
    
    public String reverseWords(String s) {
        s = s.trim();
    	char arr[] = s.toCharArray();
    	revert(arr, 0, arr.length-1);
    	StringBuilder sb = new StringBuilder();
    	int i = 0;
    	boolean f = false;
    	while (i < arr.length) {
    		if (arr[i] != ' ') { sb.append(arr[i]); f = false; }
    		else if(!f) { sb.append(' '); f = true; }
    		++i;
    	}
    	arr = sb.toString().toCharArray();
    	int j = 0; i = 0;
    	while (i < arr.length) {
    		if (arr[i] == ' ') {
    			revert(arr, j, i-1);
    			j = i+1;
    		}
    		++i;
    	}
    	revert(arr, j, i-1);
    	return String.valueOf(arr);
    }
}
