public class Solution {
    public String reverseString(String s) {
        if (s == null) {
            return s;
        }
        return new StringBuilder(s).reverse().toString();
    }
}
