import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

public class DecodeString {

    private int currIndex = 0;

    public static void main(String[] args) {
	DecodeString main = new DecodeString();
	
	System.out.println(main.decodeString("3[a]2[bc]"));
	System.out.println(main.decodeString("3[a2[c]]"));
	System.out.println(main.decodeString("2[abc]3[cd]ef"));
    }

    public String decodeString(String s) {
	if (s == null || s.isEmpty()) {
	    return s;
	}
	List<Character> ans = new ArrayList<Character>();
	s = "1[" + s + "]";
	char[] arr = s.toCharArray();
	//System.out.println(s);
	currIndex = 0;
	return helper(arr).toString();
    }

    private StringBuilder helper(char[] arr) {
	StringBuilder builder = new StringBuilder();

	int digitStartIndex = -1;
	for (; currIndex < arr.length && arr[currIndex] != ']'; ++currIndex) {
	    //System.out.println("currIndex = " + currIndex);
	    if (arr[currIndex] >= 'a' && arr[currIndex] <= 'z') {
		builder.append(arr[currIndex]);
	    } else if (arr[currIndex] >= '0' && arr[currIndex] <= '9' && digitStartIndex < 0) {
		digitStartIndex = currIndex;
	    } else if (arr[currIndex] == '[') {
		int duplicateCnt = Integer.parseInt(String.valueOf(Arrays.copyOfRange(arr, digitStartIndex, currIndex)));
		//System.out.printf("duplicate count = %d\n", duplicateCnt);
		++currIndex;
		StringBuilder subBuilder = helper(arr);
		for (int k = 0; k < duplicateCnt; ++k) {
		    builder.append(subBuilder);
		}
		digitStartIndex = -1;
	    }
	}
	return builder;
    }

    private boolean isDigit(char c) {
	return c >= '0' && c <= 9;
    }

}
