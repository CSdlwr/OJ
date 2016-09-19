public class Solution {
    public List<Integer> getRow(int rowIndex) {
        rowIndex++;
        List<List<Integer>> re = new ArrayList<List<Integer>>();
        List<Integer> l = null;
        for (int i = 0; i < rowIndex; ++i) {
        	l = new ArrayList<Integer>();
        	l.add(1);
        	for (int j = 1; j < i; ++j) 
        		l.add(re.get(i-1).get(j-1)+re.get(i-1).get(j));
        	if (i > 0) l.add(1);
        	re.add(l);
        }
        return re.get(rowIndex-1);        
    }
}
