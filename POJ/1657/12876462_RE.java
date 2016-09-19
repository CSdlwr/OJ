package p1;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int num = Integer.parseInt(scanner.nextLine());
		List<String> input = new ArrayList<String>();
		char sx, sy, ex, ey;
		while (num-- > 0) 
			input.add(scanner.nextLine());
		for (String i : input) {
//		while (true) {
//			String i = scanner.nextLine();
			String[] pairs = i.split(" ");
			sx = pairs[0].charAt(0);
			sy = pairs[0].charAt(1);
			ex = pairs[1].charAt(0);
			ey = pairs[1].charAt(1);
			int xx = Math.abs(sx - ex);
			int yy = Math.abs(sy - ey);
			if (sx == ex && sy == ey)
				System.out.println("0 0 0 0");
			else if (sx == ex) 
				System.out.print(yy + " " + 1 + " " + 1 + " Inf");
			else if (sy == ey)
				System.out.print(xx + " " + 1 + " " + 1 + " Inf");
			else if (xx == yy)
				System.out.print(xx + " " + 1 + " " + 2 + " " + 1);
			else if (xx < yy)
				System.out.print(yy + " " + 2 + " " + 2 + " Inf");
			else 
				System.out.print(xx + " " + 2 + " " + 2 + " Inf");
			System.out.println();
		}
	}

}
