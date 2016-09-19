import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] haab = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin",
				"mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan",
				"pax", "koyab", "cumhu", "uayet" };
		String[] holly = { "imix", "ik", "akbal", "kan", "chicchan", "cimi",
				"manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix",
				"mem", "cib", "caban", "eznab", "canac", "ahau" };
		List<String> haabList = Arrays.asList(haab);
		List<String> hollyList = Arrays.asList(holly);
		Scanner scanner = new Scanner(System.in);
		List<String> input = new ArrayList<String>();
		List<String> output = new ArrayList<String>();
		int num = Integer.parseInt(scanner.nextLine());
		while (num-- > 0)
			input.add(scanner.nextLine());
		String[] is = null;
		int haabYear = 0, haabDay = 0, haabMonth = 0;
		int hollyDay = 0, hollyName = 0, hollyYear = 0;
		int sum = 0;
		for (String i : input) {
			is = i.split(" ");
			haabYear = Integer.parseInt(is[2]);
			haabMonth = haabList.indexOf(is[1]);
			haabDay = Integer.parseInt(is[0].substring(0, is[0].length() - 1));
//			if (haabMonth < 18)
			if (haabYear > 0)
				sum = haabYear * 365 + haabMonth * 20 + haabDay + 1; 
			else 
				sum = haabMonth * 20 + haabDay + 1; 
			hollyYear = sum / 260;
			hollyName = sum % 20 - 1;
			hollyDay = sum % 13;
			output.add(hollyDay + " "  + hollyList.get(hollyName) + " " + hollyYear);
		}
		
		System.out.println(output.size());
		for (String o : output)
			System.out.println(o);
	}

}
