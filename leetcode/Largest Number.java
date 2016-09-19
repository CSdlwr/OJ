public class Solution {
	public String largestNumber(int[] num) {
		
		Integer[] nn = new Integer[num.length];
		
		for (int i = 0; i < num.length; ++i) {
			nn[i] = num[i];
		}
		
		Comparator<Integer> comp = new Comparator<Integer>() {
			
			@Override
			public int compare(Integer o1, Integer o2) {
				// TODO Auto-generated method stub
				Integer t1 = Integer.parseInt(String.valueOf(o1)+String.valueOf(o2));
				Integer t2 = Integer.parseInt(String.valueOf(o2)+String.valueOf(o1));
				if (t1 > t2) 
					return -1;
				else if (t1 < t2)
					return 1;
				return 0;
			}
		};
		
		Arrays.sort(nn, comp);
		
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < nn.length; ++i)
			sb.append(nn[i]);
		int i = 0;
		while (i < sb.length() && sb.charAt(i) == '0')
			++i;
		String s = sb.substring(i);
		if (s.length() == 0) return "0";
		return s;
	}
}
