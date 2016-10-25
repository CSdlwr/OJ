import java.util.Arrays;

import java.util.List;
import java.util.ArrayList;

public class BinaryWatch {
    
    private List<String> ans;

    public static void main(String[] args) {
	BinaryWatch main = new BinaryWatch();
	System.out.println(main.readBinaryWatch(2));
    }

    public List<String> readBinaryWatch(int num) {
	char[] watch = new char[10];
	for (int i = 0; i < watch.length; ++i) {
	    watch[i] = '0';
	}
	ans = new ArrayList<String>();
	traverse(watch, 0, num);
	return ans;
    }

    private void traverse(char[] watch, int currIndex, int remaining) {
	if (remaining == 0) {
	    String h = String.valueOf(Arrays.copyOfRange(watch, 0, 4));
	    String m = String.valueOf(Arrays.copyOfRange(watch, 4, watch.length));
	    int hour = Integer.valueOf(h, 2);
	    int minute = Integer.valueOf(m, 2);
	    //System.out.printf("h = %s, hour = %d\n", h, hour);
	    //System.out.printf("m = %s, minute = %d\n", m, minute);
	    if (hour <= 11 && minute <= 59) {
		if (minute < 10) {
		    ans.add(hour + ":0" + minute);
		} else {
		    ans.add(hour + ":" + minute);
		}
	    }
	    return;
	}

	if (currIndex >= watch.length) {
	    return;
	}
	watch[currIndex] = '1';
	traverse(watch, currIndex + 1, remaining - 1);
	watch[currIndex] = '0';
	traverse(watch, currIndex + 1, remaining);
    }

}
