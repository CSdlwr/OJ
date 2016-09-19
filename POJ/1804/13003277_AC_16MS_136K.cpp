#include<iostream>
using namespace std;

int a[1005], t[1005];
int tt, n;
int cnt;

void mergeSort(int* a, int x, int y, int *t) {
	if (y - x > 1) {
		int m = x + (y-x)/2;
		int p = x, q = m, i = x;
		mergeSort(a, x, m, t);
		mergeSort(a, m, y, t);
		while (p < m || q < y) {
			if (q >= y || (p < m && a[p] <= a[q])) t[i++] = a[p++];
			else { t[i++] = a[q++]; cnt += m-p; }
		}
		for (int i = x; i < y; ++i) a[i] = t[i];
	}
}

int main() {
	scanf("%d", &tt);
	for (int i = 1; i <= tt; ++i) {
		scanf("%d", &n);
		for (int j = 0; j < n; ++j) 
			scanf("%d", &a[j]);
		cnt = 0;
		mergeSort(a, 0, n, t);
		printf("Scenario #%d:\n", i);
		printf("%d\n\n", cnt);
	}
	return 0;
}