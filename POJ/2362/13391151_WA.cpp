#include<stdio.h>
#include<string.h>

int t;
int a[20], al;
bool vs[20];
int sum, el, eCnt;

bool judge(int st, int lt) {
	if (lt == 0) {
		if (++eCnt == 3) return true;
		st = 0; lt = el;
	}
	for (int i = st; i < al; ++i) {
		if (!vs[i] && a[i] <= lt) {
			vs[i] = 1;
			if (judge(i+1, lt-a[i])) return true;
			vs[i] = 0;
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
		qs(a, 0, al-1);
		if (a[0] > el) { printf("no\n"); continue; }
		memset(vs, 0, sizeof(vs));
		eCnt = 0;
		if (judge(0, el)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}