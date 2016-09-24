public class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        if (ransomNote.length() > magazine.length()) {
            return false;
        }
        
        char[] rArr = ransomNote.toCharArray();
        char[] mArr = magazine.toCharArray();
        Arrays.sort(rArr);
        Arrays.sort(mArr);
        
        int i = 0;
        int j = 0;
        
        while (i < rArr.length && j < mArr.length) {
            if (rArr[i] == mArr[j]) {
                ++i;
                ++j;
            } else if (rArr[i] > mArr[j]) {
                ++j;
            } else if (rArr[i] < mArr[j]) {
                return false;
            }
        }
        if (i < rArr.length) {
            return false;
        }
        return true;
    }
}
