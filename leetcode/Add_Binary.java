public class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int i = a.length()-1, j = b.length()-1;
        int ca = 0;
        int t = 0;
        while (i >= 0 || j >= 0 || ca > 0) {
        	t = 0; t += ca;
        	if (i >= 0) t += a.charAt(i--) - '0';
        	if (j >= 0) t += b.charAt(j--) - '0';
        	sb.append(t%2);
        	ca = t/2;
        }
        return sb.reverse().toString();        
    }
}
