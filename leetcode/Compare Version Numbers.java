public class Solution {
    public int compareVersion(String version1, String version2) {
        String[] vs1 = version1.split("\\.");
        String[] vs2 = version2.split("\\.");
        int i = 0;
        String a = null, b = null;
        while (i < vs1.length || i < vs2.length) {
        	if (i < vs1.length) a = vs1[i];
        	else a = "0";
        	if (i < vs2.length) b = vs2[i];
        	else b = "0";
            if (!a.equals(b)) {
            	int t = atoi(a)-atoi(b);
                return t > 0 ? 1 : t == 0 ? 0 : -1;
            }
            ++i;
        }
        return 0;
    }

    public int atoi(String a) {
        int n = 0;
        for (int i = 0; i < a.length(); ++i) {
            n = n*10+a.charAt(i)-'0';
        }
        return n;
    }
}
