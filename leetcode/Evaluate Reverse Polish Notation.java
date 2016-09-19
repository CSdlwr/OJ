public class Solution {
    
	public int getNum(String s) {
		int ans = 0;
		for (int i = 0; i < s.length(); ++i) 
			ans = ans * 10 + s.charAt(i)-'0';
		return ans;
	}
    
    public int evalRPN(String[] tokens) {
		Stack<Integer> st = new Stack<Integer>();
		int a, b;
		for (String s : tokens) {
			if (s.length() > 1) {
				if (s.charAt(0) > '9' || s.charAt(0) < '0') {
					a = getNum(s.substring(1));
					a *= -1;
					st.push(a);
				} else {
					st.push(getNum(s));
				}
			} else if (s.charAt(0) <= '9' && s.charAt(0) >= '0') {
				st.push(s.charAt(0)-'0');
			} else {
				a = st.pop();
				b = st.pop();
				if (s.charAt(0) == '+') st.push(b+a);
				else if (s.charAt(0) == '-') st.push(b-a);
				else if (s.charAt(0) == '*') st.push(b*a);
				else st.push(b/a);
			}
		}
		return st.pop();
    }
}
