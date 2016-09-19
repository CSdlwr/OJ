public class Solution {
    public String simplifyPath(String path) {
		if (path == null || path.length() == 0)
			return path;
		path += "/";
		Stack<String> st = new Stack<String>();
		StringBuilder sb = new StringBuilder();
		char arr[] = path.toCharArray();
		for (int i = 0; i < arr.length; ++i) {
			if (arr[i] == '/' && sb.length() != 0) {
				if (sb.toString().equals("..") && st.size() > 0) 
					st.pop();
				else if (!sb.toString().equals(".") 
						&& !sb.toString().equals(".."))
					st.add(sb.toString());
				sb.delete(0, sb.length());
			} else if (arr[i] != '/') {
				sb.append(arr[i]);
			}
		}
		sb.delete(0, sb.length());
		int i = 0;
		do {
			sb.append("/");
			if (!st.empty()) 
				sb.append(st.get(i++));
		} while (i < st.size());
		return sb.toString();
    }
}
