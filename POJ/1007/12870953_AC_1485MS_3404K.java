import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int len = scanner.nextInt();
		int num = scanner.nextInt();
		List<Integer> unSortedCount = new ArrayList<Integer>();
		List<Integer> counts = new ArrayList<Integer>();
		List<String> lists = new ArrayList<String>();
		while (num-- > 0) 
//			while (len-- > 0) 
				lists.add(scanner.next());
		int count = 0;
		String str = null;
		int i = 0, j = 0, k = 0;
		for (; i < lists.size(); ++i) {
			count = 0;
			j = 0;
			str = lists.get(i);
			while (j < str.length()) {
				if (str.charAt(j) != 'A') {
					k = j + 1;
					while (k < str.length()) {
						if (str.charAt(j) > str.charAt(k))  {
							++count;
						}
						++k;
					}
				}
				++j;
			}
			unSortedCount.add(count);
			counts.add(count);
		}
		Collections.sort(counts);
		for (Integer c : counts) 
			System.out.println(lists.get(unSortedCount.indexOf(c)));
	}
	

}
