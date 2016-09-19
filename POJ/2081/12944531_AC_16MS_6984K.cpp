#include <iostream>
using namespace std;
#define MAXK 500005
#define MAXV 5000005

bool vs[MAXV];
int a[MAXK];

int main() {
	a[0] = 0;
	memset(vs, 0, sizeof(vs));
	vs[0] = true;
	int t;
	for (int i = 1; i < MAXK; ++i) {
		t = a[i-1] - i;
		if (t > 0 && !vs[t]) a[i] = t;
		else a[i] = a[i-1] + i;
		vs[a[i]] = true;
	}

	int k;
	while (scanf("%d", &k)) {
		if (k == -1) break;
		else printf("%d\n", a[k]);
	}
	return 0;
}