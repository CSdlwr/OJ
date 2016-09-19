#include<stdio.h>

int a[32768], b[32768];
int max;

int main() {
	int t = 1;
	while (scanf("%d", &a[0])) {
		if (a[0] == -1) break;
		max = 1; b[0] = 1;
		for (int i = 1; ; ++i) {
			scanf("%d", &a[i]);
			if (a[i] == -1) break;
			b[i] = 1;
			for (int j = 0; j < i; ++j)
				if (a[j] >= a[i] && b[j]+1 > b[i]) {
					b[i] = b[j]+1;
					if (b[i] > max) max = b[i];
				}
		}
		if (t != 1) printf("\n");
		printf("Test #%d:\n", t++);
		printf("  maximum possible interceptions: %d\n", max);
	}
	return 0;
}