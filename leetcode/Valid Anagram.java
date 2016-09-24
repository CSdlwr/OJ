public class Solution {
    public boolean isAnagram(String s, String t) {
        if (s != null && t != null) {
            if (s.length() != t.length()) {
                return false;
            } else {
                char[] sArr = s.toCharArray();
                char[] tArr = t.toCharArray();
                Arrays.sort(sArr);
                Arrays.sort(tArr);
                
                for (int i = 0; i < sArr.length; ++i) {
                    if (sArr[i] != tArr[i]) {
                        return false;
                    }
                }
                return true;
            }
        } else if (s != null) {
            return s.equals(t);
        } else if (t == null) {
            return true;
        }
        return false;
    }
}
