#include <iostream>
#include <math.h>
using namespace std;

void swap(int* a, int *b);
int partition(int *a, int p, int r);
void qsort(int* a, int p, int r);

int main() {
	int inp[3005];
	while (scanf("%d %d", &inp[0], &inp[1]) != EOF) {
		if (inp[0] == 1) {
			if (inp[1] == 1) printf("Jolly\n");
			else printf("Not jolly\n");
			continue;
		}
		for (int i = 2; i <= inp[0]; ++i) {
			scanf("%d", &inp[i]);
			inp[i-1] = abs(inp[i] - inp[i-1]);
		}
		qsort(inp, 1, inp[0]);
		bool f = true;
		for (int i = 1; i < inp[0]; ++i)
			if (inp[i] != i) {
				f = false;
				break;
			}
		if (f) printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}

void swap(int* a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int *a, int p, int r) {
	int i = p - 1;
	int j = p;
	while (j < r) {
		if (a[j] <= a[r]) {
			++i;
			swap(a+j, a+i);
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
