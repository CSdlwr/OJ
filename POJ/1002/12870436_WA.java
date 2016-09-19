import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List<String> finalResults = new ArrayList<String>();
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		List<String> nums = new ArrayList<String>();
		while (n-- > 0) 
			nums.add(s.next());
		Map<String, Integer> results = new HashMap<String, Integer>();
		String mapKey = null;
		for (String num : nums) {
			mapKey = Main.convert(num);
			if (results.containsKey(mapKey))
				results.put(mapKey, results.get(mapKey) + 1);
			else
				results.put(mapKey, 1);
		}
		for (String key : results.keySet())
			if (results.get(key) != 1) 
				finalResults.add(key + " " + results.get(key));
		Collections.sort(finalResults);
		for (String f : finalResults)
			System.out.println(f);
	}
	
	public static String convert(String s) {
		String[] ss = s.split("-");
		String result = "";
		int i = 0;
		while (i < ss.length)
			result += ss[i++];
		StringBuilder builder = new StringBuilder(result);
		builder.insert(3, '-');
		Main.standardize(builder);
		return builder.toString();
	}
	
	public static void standardize(StringBuilder s) {
		for (int i = 0; i < s.length(); ++i) {
			switch (s.charAt(i)) {
				case 'A':
				case 'B':
				case 'C': {
					s.replace(i, i+1, "2");
					break;
				}
				case 'D':
				case 'E':
				case 'F': {
					s.replace(i, i+1, "3");
					break;
				}
				case 'G':
				case 'H':
				case 'I': {
					s.replace(i, i+1, "4");
					break;
				}
				case 'J':
				case 'K':
				case 'L': {
					s.replace(i, i+1, "5");
					break;
				}
				case 'M':
				case 'N':
				case 'O': {
					s.replace(i, i+1, "6");
					break;
				}
				case 'P':
				case 'R':
				case 'S': {
					s.replace(i, i+1, "7");
					break;
				}
				case 'T':
				case 'U':
				case 'V': {
					s.replace(i, i+1, "8");
					break;
				}
				case 'W':
				case 'X':
				case 'Y': {
					s.replace(i, i+1, "9");
					break;
				}
				default : break;
			}
		}
	}
}
