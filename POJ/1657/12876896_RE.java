package p1;

import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int num = Integer.parseInt(scanner.nextLine());
		String input = null;
		int n = 0;
		while (n++ < num) {
			input = scanner.nextLine();
			String[] pairs = input.split(" ");
			int xx = Math.abs(pairs[0].charAt(0) - pairs[1].charAt(0));
			int yy = Math.abs(pairs[0].charAt(1) - pairs[1].charAt(1));
			if (pairs[0].charAt(0) == pairs[1].charAt(0)
					&& pairs[0].charAt(1) == pairs[1].charAt(1))
				System.out.println("0 0 0 0");
			else if (pairs[0].charAt(0) == pairs[1].charAt(0))
				System.out.print(yy + " " + 1 + " " + 1);
			else if (pairs[0].charAt(1) == pairs[1].charAt(1))
				System.out.print(xx + " " + 1 + " " + 1);
			else if (xx == yy)
				System.out.print(xx + " " + 1 + " " + 2);
			else if (xx < yy)
				System.out.print(yy + " " + 2 + " " + 2);
			else
				System.out.print(xx + " " + 2 + " " + 2);
			if (xx == yy)
				System.out.println(" 1");
			else if ((xx + yy) % 2 == 0)
				System.out.println(" 2");
			else
				System.out.println(" Inf");
		}
	}

}
