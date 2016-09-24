public class Solution {
    public int firstUniqChar(String s) {
        char[] sArr = s.toCharArray();
        int[] charShowTimes = new int[26];
        int[] charFirstShowIndexInString = new int[26];

        for (int i = 0; i < charFirstShowIndexInString.length; ++i) {
            charFirstShowIndexInString[i] = -1;
        }

        for (int i = 0; i < sArr.length; ++i) {
            if (charFirstShowIndexInString[sArr[i] - 'a'] < 0) {
                charFirstShowIndexInString[sArr[i] - 'a'] = i;
            }
            charShowTimes[sArr[i] - 'a']++;
        }

        int ans = -1;
        for (int i = 0; i < charShowTimes.length; ++i) {
            if (charShowTimes[i] == 1) {
                if (ans == -1) {
                    ans = charFirstShowIndexInString[i];
                } else if (ans > charFirstShowIndexInString[i]) {
                    ans = charFirstShowIndexInString[i];
                }
            }
        }
        return ans;
    }
}
