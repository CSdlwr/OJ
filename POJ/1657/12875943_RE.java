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
		List<Integer> steps = new ArrayList<Integer>();
		char sx, sy, ex, ey;
		while (num-- > 0) 
			input.add(scanner.nextLine());
		for (String i : input) {
			String[] pairs = i.split(" ");
			sx = pairs[0].charAt(0);
			sy = pairs[0].charAt(1);
			ex = pairs[1].charAt(0);
			ey = pairs[1].charAt(1);
			steps.add(cal_wang(sx, sy, ex, ey));
			steps.add(cal_hou(sx, sy, ex, ey));
			steps.add(cal_che(sx, sy, ex, ey));
			steps.add(cal_xiang(sx, sy, ex, ey));
			for (int s : steps) {
				if (s > 0)
					System.out.print(s + " ");
				else System.out.print("Inf");
			}
			steps.clear();
			System.out.println();
		}
	}

	public static int cal_wang(char sx, char sy, char ex, char ey) {
		int step = -1;
		int xx = Math.abs(sx - ex);
		int yy = Math.abs(sy - ey);
		if (sx == ex) {
			step = sy - ey;
			return Math.abs(step);
		} else if (sy == ey) {
			step = sx - ex;
			return Math.abs(step);
		} else if (xx == yy) {
			step = sy - ey;
			return Math.abs(step);
		} else {
			step = 0;
			int small = xx > yy ? yy : xx;
			int dist = Math.abs(xx - yy);
			step += small;
			step += dist;
		}
		return step;
	}
	
	public static int cal_hou(char sx, char sy, char ex, char ey) {
		int step = -1;
		int xx = Math.abs(sx - ex);
		int yy = Math.abs(sy - ey);
		if (sx == ex || sy == ey || xx == yy) 
			step = 1;
		else step = 2;
		return step;
	}
	
	public static int cal_che(char sx, char sy, char ex, char ey) {
		int step = -1;
		if (sx == ex || sy == ey) 
			step = 1;
		else step = 2;
		return step;
	}

	public static int cal_xiang(char sx, char sy, char ex, char ey) {
		int step = -1;
		int xx = Math.abs(sx - ex);
		int yy = Math.abs(sy - ey);
		if (xx == yy)
			step = 1;
		return step;
	}
}
