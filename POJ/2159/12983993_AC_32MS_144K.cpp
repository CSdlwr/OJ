#include<iostream>
#include<string.h>
using namespace std;

char s1[105], s2[105];
int vs1[27], vs2[27];
int k1, k2;
int len;
bool fd;

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int a[], int p, int r) {
	int i = p-1;
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

int main() {
	while (scanf("%s%s", s1, s2) != EOF) {
		fd = true;
		len = strlen(s1);
		k1 = k2 = 0;
		memset(vs1, 0, sizeof(vs1));
		memset(vs2, 0, sizeof(vs2));
		for (int i = 0; i < len; ++i) {
			if (vs1[s1[i]-'A'] == 0) ++k1;
			if (vs2[s2[i]-'A'] == 0) ++k2;
			vs1[s1[i]-'A']++;
			vs2[s2[i]-'A']++;
		}
		if (k1 != k2) {printf("NO\n"); continue;}
		qsort(vs1, 0, 25);
		qsort(vs2, 0, 25);
		for (int i = 0; i < 26; ++i)
			if (vs1[i] != vs2[i]) {fd = false; break;}
		if (fd) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}