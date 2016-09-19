#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

int t;
int a[21], al;
bool vs[21];
int sum, el, cnt;
int p[10];

bool judge(int root, int st, int lt) {
	if (lt == 0) {
		if (++cnt == 3) return true;
		int j = 0;
		while (vs[j]) j++;
		if (judge(j, j, el)) return true;
		--cnt;
	}
	else for (int i = st; i < al; ++i) {
		if (!vs[i] && a[i] <= lt) {
			vs[i] = true;
			if (judge(root, st+1, lt-a[i])) return true;
			vs[i] = false;
			if (i == root) return false;
			while (a[i+1] == a[i]) ++i;
		}
	}
	return false;
}

void swap(int* a, int* b) {
	int t = *a; *a = *b; *b = t;
}

int partition(int a[], int p, int r) {
	int j = p, i = j-1;
	int x = a[r];
	while (j < r) {
		if (a[j] > x) {
			++i; swap(a+i, a+j);
		}
		++j;
	}
	++i;
	swap(a+i, a+r);
	return i;
}

void qs(int a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		qs(a, p, q-1);
		qs(a, q+1, r);
	}
}

int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &al);
		sum = 0;
		for (int i = 0; i < al; ++i) {
			scanf("%d", a+i);
			sum += a[i];
		}
		if (sum % 4) { printf("no\n"); continue; }
		el = sum / 4;
//		qs(a, 0, al-1);
		sort(a, a+al);
		if (a[0] > el) { printf("no\n"); continue; }
		memset(vs, 0, sizeof(vs));
		cnt = 0;
		if (judge(0, 0, el)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}