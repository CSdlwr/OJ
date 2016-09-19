#include<iostream>
#include<stack>
using namespace std;

int c[1005];
int n;
stack <int> st;

int main() {
	while (scanf("%d", &n)) {
		if (n == 0) break;
		while (scanf("%d", &c[0])) {
			if (c[0] == 0) break;
			for (int i = 1; i < n; ++i) 
				scanf("%d", &c[i]);
			int i = 1, ii = 0;
			while (1) {
				if (st.empty() && i <= n) {
					st.push(i++);
				}
				if (st.top() == c[ii]) {
					st.pop();
					if (++ii == n) break;
				} 
				else if (i <= n) st.push(i++);
				else break;
			}
			if (ii == n) printf("YES\n");
			else printf("NO\n");
			while (!st.empty())
				st.pop();
		}
		printf("\n");
	}
	return 0;
}