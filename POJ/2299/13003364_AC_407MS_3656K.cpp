#include<iostream>
using namespace std;

int a[500005], t[500005];
int n;
long long cnt;

void mergeSort(int* a, int x, int y, int* t){
	if (y-x > 1) {
		int m = x + (y-x)/2;
		int p = x, q = m, i = x;
		mergeSort(a, x, m, t);
		mergeSort(a, m, y, t);
		while (p < m || q < y) {
			if (q >= y || (p < m && a[p] <= a[q])) t[i++] = a[p++];
			else { t[i++] = a[q++]; cnt += m-p; }
		}
		for (i = x; i < y; ++i) a[i] = t[i];
	}
}

int main() {
	while (scanf("%d", &n)) {
		if (n == 0) break;
		cnt = 0;
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		mergeSort(a, 0, n, t);
		printf("%I64d\n", cnt);
	}
	return 0;
}