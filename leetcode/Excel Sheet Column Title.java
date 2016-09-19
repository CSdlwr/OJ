public class Solution {
    public String convertToTitle(int n) {
        String dict = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        StringBuilder sb = new StringBuilder();
        while (n > 26) {
            int t = n%26;
            if (t == 0) {
                sb.append('Z');
                n /= 26;
                --n;
            } else {
                sb.append(dict.charAt(t));
                n /= 26;
            }
        }
        sb.append(dict.charAt(n));
        sb.trimToSize();
        return sb.reverse().toString();   
    }
}
