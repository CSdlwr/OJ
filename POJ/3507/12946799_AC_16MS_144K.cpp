#include <iostream>
using namespace std;

void swap(int* a, int* b);
int partition(int* a, int p, int r);
void qsort(int* a, int p, int r);

int main() {
	int inp[7];
	bool f;
	while (1) {
		f = true;
		for (int i = 0; i < 6; ++i) {
			scanf("%d", &inp[i]);
			if (inp[i] != 0) f = false;
		}
		if (f) break;
		qsort(inp, 0, 5);
		int sum = 0;
		for (int i = 1; i <= 4; ++i)
			sum += inp[i];
		if (sum % 4 == 0) printf("%d\n", sum/4);
		else printf("%g\n", sum * 1.0 / 4);
	}
	return 0;
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int* a, int p, int r) {
	int i = p - 1;
	int j = p;
	while (j < r) {
		if (a[j] <= a[r]) {
			++i;
			swap(a+i, a+j);
		}
		++j;
	}
	++i;
	swap(a+i, a+r);
	return i;
}

void qsort(int* a, int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		qsort(a, p, q-1);
		qsort(a, q+1, r);
	}
}