package p1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main{

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(reader.readLine());
		StringBuilder builder = new StringBuilder();
		List<String> output = new ArrayList<String>();
		String input = null;
		int n = 0;
		while (n++ < num) {
//			builder = ;
			input = reader.readLine();
			String[] pairs = input.split(" ");
			int xx = Math.abs(pairs[0].charAt(0) - pairs[1].charAt(0));
			int yy = Math.abs(pairs[0].charAt(1) - pairs[1].charAt(1));
			if (pairs[0].charAt(0) == pairs[1].charAt(0)
					&& pairs[0].charAt(1) == pairs[1].charAt(1))
				System.out.println("0 0 0 0");
			else if (pairs[0].charAt(0) == pairs[1].charAt(0))
				builder.append(yy).append(" ").append(1).append(" ").append(1);
			else if (pairs[0].charAt(1) == pairs[1].charAt(1))
				builder.append(xx).append(" ").append(1).append(" ").append(1);
			else if (xx == yy)
				builder.append(xx).append(" ").append(1).append(" ").append(2);
			else if (xx < yy)
				builder.append(yy).append(" ").append(2).append(" ").append(2);
			else
				builder.append(xx).append(" ").append(2).append(" ").append(2);
			if (xx == yy)
				builder.append(" 1");
			else if ((xx + yy) % 2 == 0)
				builder.append(" 2");
			else
				builder.append(" Inf");
			//System.out.println(builder.toString());
			output.add(builder.toString());
			builder.delete(0, builder.length());
		}
		
		for (String s : output)
			System.out.println(s);
	}

}
