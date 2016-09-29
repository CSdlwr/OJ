public class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Character> registry = new HashMap<Character, Character>();
        char[] sArr = s.toCharArray();
        char[] tArr = t.toCharArray();

        for (int i = 0; i < sArr.length; ++i) {
            Character source = registry.get(sArr[i]);
            char dest = tArr[i];
            if (source == null) {
                source = sArr[i];
                registry.put(source, dest);
            } else if (source != dest) {
                return false;
            }
        }
        
        List<Character> values = new ArrayList<Character>(registry.values());
        Collections.sort(values);
        for (int i = 1; i < values.size(); ++i) {
            if (values.get(i).equals(values.get(i - 1))) {
                return false;
            }
        }
        return true;
    }
}
