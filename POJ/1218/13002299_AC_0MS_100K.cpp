#include<iostream>
#include<string.h>
using namespace std;

int t, n;
bool vs[105];
int ans;
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &n);
		ans = 0;
		memset(vs, 0, sizeof(vs));
		for (int i = 1; i <= n; ++i) 
			for (int j = 1; j <= n; ++j) 
				if (j%i==0) vs[j] = !vs[j];
		for (int i = 1; i <= n; ++i)
			if (vs[i]) ++ans;
		printf("%d\n", ans);
	}
	return 0;
} 