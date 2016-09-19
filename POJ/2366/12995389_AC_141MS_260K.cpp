#include<iostream>
using namespace std;

int n;
int a[50005];
int b;
bool f = false;

int binSearch(int a[], int n, int k) {
	int l = 0, r = n-1;
	int m;
	while (l <= r) {
		m = (l+r)/2;
		if (a[m] > k) r = m-1;
		else if (a[m] < k) l = m+1;
		else return m;
	}
	return -1;
}

int main() {
	scanf("%d", &n);
	int len = n;
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b);
		if (!f && binSearch(a, len, 10000-b) >= 0) f = true;
	}
	if (f) printf("YES\n");
	else printf("NO\n");
	return 0;
}