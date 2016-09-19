import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int num = scanner.nextInt();
		scanner.nextLine();
		while (num-- > 0) {
			int real[] = new int[12];
			int hl[] = new int[12];
			String[][] input = new String[3][4];
			int i = 0; 
			while (i < 3) 
				input[i++] = scanner.nextLine().split(" ");
			for (i = 0; i < 3; ++i) {
				if (input[i][2].equals("even"))
					for (int j = 0; j < 2; ++j)
						for (int k = 0; k < input[i][j].length(); ++k)
							real[input[i][j].charAt(k) - 'A'] = 1;
				else if (input[i][2].equals("up")) {
					for (int k = 0; k < input[i][0].length(); ++k)
						hl[input[i][0].charAt(k)-'A']++;
					for (int k = 0; k < input[i][1].length(); ++k)
						hl[input[i][1].charAt(k)-'A']--;
				}
				else {
					for (int k = 0; k < input[i][0].length(); ++k)
						hl[input[i][0].charAt(k)-'A']--;
					for (int k = 0; k < input[i][1].length(); ++k)
						hl[input[i][1].charAt(k)-'A']++;
				}
			}
			int max = 0;
			for (i = 0; i < 12; ++i) {
				if (real[i] == 1)
					hl[i] = 0;
				if (Math.abs(hl[i]) > Math.abs(hl[max]))
					max = i;
			}
			char fade = (char) (max + (int)'A');
			System.out.print(fade + " is the counterfeit coin and it is ");
			for (i = 0; i < 3; ++i)
				if (input[i][2].equals("up")) {
					if (input[i][0].indexOf(fade) >= 0) {
						System.out.println("heavy.");
						break;
					}
					else if (input[i][1].indexOf(fade) >= 0) {
						System.out.println("light.");
						break;
					}
				} else if (input[i][2].equals("down")) {
					if (input[i][0].indexOf(fade) >= 0) {
						System.out.println("light.");
						break;
					}
					else if (input[i][1].indexOf(fade) >= 0) {
						System.out.println("heavy.");
						break;
					}
				}
		}
	}
}