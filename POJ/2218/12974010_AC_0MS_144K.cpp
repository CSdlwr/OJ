#include<iostream>
#include<string.h>
using namespace std;
struct info {
	char n[22];
	int w;
}is[15];
void swap(info* a, info* b);
int partition(info a[], int p, int r);
void qsort(info a[], int p, int r);
char in[22];
int d, b;
int cnt = 0;
int main() {
	while (scanf("%s", in) != EOF) {
		if (strcmp(in, "START") == 0) continue;
		else if (strcmp(in, "END") == 0) {
			qsort(is, 0, cnt-1);
			for (int i = 0; i < cnt; ++i)
				printf("%s\n", is[i].n);
			printf("\n");
			cnt = 0;
		} else {
			strcpy(is[cnt].n, in);
			scanf(" %d %d", &d, &b);
			is[cnt++].w = b-d;
		}
	}
	return 0;
}

void swap(info* a, info* b) {
	info t = *a;
	*a = *b;
	*b = t;
}

int partition(info a[], int p, int r) {
	int i = p-1;
	int j = p;
	int x = a[r].w;
	while (j < r) {
		if (a[j].w > x) {
			++i;
			swap(a+i, a+j);
		}
		++j;
	}
	++i;
	swap(a+i, a+r);
	return i;
}

void qsort(info a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		qsort(a, p, q-1);
		qsort(a, q+1, r);
	}
}