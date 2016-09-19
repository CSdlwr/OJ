package p1;

import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int num = Integer.parseInt(scanner.nextLine());
		String input = null;
		char sx, sy, ex, ey;
		int n = 0;
		while (n++ < num) {
			input = scanner.nextLine();
			String[] pairs = input.split(" ");
			sx = pairs[0].charAt(0);
			sy = pairs[0].charAt(1);
			ex = pairs[1].charAt(0);
			ey = pairs[1].charAt(1);
			int xx = Math.abs(sx - ex);
			int yy = Math.abs(sy - ey);
			if (sx == ex && sy == ey)
				System.out.println("0 0 0 0");
			else if (sx == ex)
				System.out.print(yy + " " + 1 + " " + 1);
			else if (sy == ey)
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
