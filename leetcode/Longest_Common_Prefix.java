public class Solution {
    public String longestCommonPrefix(String[] strs) {
		if (strs == null || strs.length == 0) return "";
        StringBuilder sb = new StringBuilder();
        int len = 0xfffffff;
        for (int i = 0; i < strs.length; ++i) 
        	if (strs[i].length() < len) len = strs[i].length();
        boolean fg = false;
        for (int i = 0; i < len; ++i) {
        	fg = false;
        	for (int j = 1; j < strs.length; ++j) 
        		if (strs[j].charAt(i) != strs[j-1].charAt(i)) fg = true;
        	if (fg) break;
        	else sb.append(strs[0].charAt(i));
        }
        return sb.toString();
    }
}
