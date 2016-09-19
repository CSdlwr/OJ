#include<iostream>
using namespace std;
void swap(int *a, int *b);
int partition(int a[], int p, int r);
void qsort(int a[], int p, int r);
int main () {
	int c;
	int sc[1005], sn;
	double avg, sum;
	scanf("%d", &c);
	while (c-- > 0) {
		scanf("%d", &sn);
		sum = 0;
		for (int i = 0; i < sn; ++i) {
			scanf("%d", &sc[i]);
			sum += sc[i];
		}
		avg = sum / sn;
		qsort(sc, 0, sn-1);
		int i = 0;
		for (; i < sn && sc[i] <= avg; ++i);
		sum = (sn-i)*1.0/sn;
		printf("%.3lf%\n", sum*100);
	}
	return 0;
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int a[], int p, int r) {
	int i = p - 1;
	int j = p;
	int x = a[r];
	while (j < r) {
		if (a[j] < x) {
			++i;
			swap(a+i, a+j);
		}
		++j;
	}
	++i;
	swap(a+i, a+r);
	return i;
}

void qsort(int a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		qsort(a, p, q-1);
		qsort(a, q+1, r);
	}
}