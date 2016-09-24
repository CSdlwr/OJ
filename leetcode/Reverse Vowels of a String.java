public class Solution {
    public String reverseVowels(String s) {
        if (s == null) {
            return s;
        }
        char[] sArr = s.toCharArray();
        int i = 0;
        int j = sArr.length - 1;
        while (i <= j) {
            if (isVowels(sArr[i]) && isVowels(sArr[j])) {
                char t = sArr[i];
                sArr[i] = sArr[j];
                sArr[j] = t;

                ++i;
                --j;
            }

            if (i < sArr.length && !isVowels(sArr[i])) {
                ++i;
            }

            if (j >= 0 && !isVowels(sArr[j])) {
                --j;
            }
        }
        return String.valueOf(sArr);
    }
    
    private boolean isVowels(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
}
