import java.math.BigDecimal;
import java.util.Scanner;


public class Main{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
//		List<String[]> numbers = new ArrayList<String[]>();
		String str = null;
		String[] input = new String[2];
		BigDecimal n = null;
		int e = 0;
		while (scanner.hasNext()) {
			str = scanner.nextLine();
			input = str.split(" ");
			n = BigDecimal.valueOf(Double.parseDouble(input[0]));
			if (input.length == 2)
				e = Integer.parseInt(input[1]);
			else e = Integer.parseInt(input[2]);
			n = n.pow(e);
			if (n.compareTo(new BigDecimal(1)) > 0)
				System.out.println(n.stripTrailingZeros().toPlainString());
			else {
				System.out.println(n.stripTrailingZeros().toPlainString().substring(1));
			}
		}
	}

}
