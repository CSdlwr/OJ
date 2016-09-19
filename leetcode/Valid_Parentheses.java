public class Solution {
    public boolean isValid(String s) {
    	Stack<Character> st = new Stack<Character>();
		char ch, cc;
		for (int i = 0; i < s.length(); ++i) {
			ch = s.charAt(i);
			if (ch == '(' || ch == '[' || ch == '{') st.push(ch);
			else {
				if (st.empty()) return false;
				cc = st.pop();
				if ((ch == ')' && cc != '(')
					|| (ch == ']' && cc != '[')
					|| (ch == '}' && cc != '{')) return false;
			}
		}
		if (st.empty())	return true;
		return false;
    }
}
