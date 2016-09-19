import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int num = Integer.parseInt(scanner.nextLine());
		while (num -- > 0) {
			int i = 0;
			String input;
			String real = "", fade = "", suspicion = "";
			int e = 0, d = 0, u = 0;
			while (i++ < 3) {
				input = scanner.nextLine();
				String[] s = input.split(" ");
				if (s[2].equals("even")) {
					real += s[0];
					real += s[1];
					e++;
				} else {
					if (s[2].equals("down"))
						d++;
					else
						u++;
					suspicion += s[0];
					suspicion += s[1];
				} 
			}
			String cs;
			for (int j = 0; j < suspicion.length(); ++j) {
				cs = String.valueOf(suspicion.charAt(j));
				if (!real.contains(cs)) {
					fade = cs;
					break;
				}
			}
			StringBuilder sb = new StringBuilder(fade);
			sb.append(" is the counterfeit coin and it is ");
			if (d != 0) {
				if (suspicion.indexOf(fade) > suspicion.length() / 2)
					sb.append("heavy.");
				else sb.append("light.");
			} else {
				if (suspicion.indexOf(fade) > suspicion.length() / 2)
					sb.append("light.");
				else sb.append("heavy.");
			}
			System.out.println(sb.toString());
		}
	}

}