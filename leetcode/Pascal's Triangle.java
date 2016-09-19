public class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> re = new ArrayList<List<Integer>>();
        List<Integer> l = null;
        for (int i = 0; i < numRows; ++i) {
        	l = new ArrayList<Integer>();
        	l.add(1);
        	for (int j = 1; j < i; ++j) 
        		l.add(re.get(i-1).get(j-1)+re.get(i-1).get(j));
        	if (i > 0) l.add(1);
        	re.add(l);
        }
        return re;
    }
}
