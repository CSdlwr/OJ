#include<iostream>
#include<malloc.h>
using namespace std;
#define HASH 90001

struct node {
	int cnt;
	int sum;
	node* next;
};

node* hp[HASH];
node* hm[HASH];
int a[4005], b[4005], c[4005], d[4005];
int n;
int main () {
	int sum, ans, h;
	node *np, *tp;
	while (scanf("%d", &n) != EOF) {
		ans = 0;
		for (int i = 0; i < n; ++i) 
			scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
		bool fd;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				fd = false;
				sum = a[i]+b[j];
				if (sum < 0) {
					h = -1*sum;
					h %= HASH;
					tp = hm[h];
				} else {
					h = sum%HASH;
					tp = hp[h];
				}
				while (tp) {
					if (tp->sum == sum) {
						tp->cnt++;
						fd = true;
						break;
					}
					tp = tp->next;
				}
				if (!fd) {
					np = (node*)malloc(sizeof(node));
					np->sum = sum;
					np->cnt = 1;
					if (sum < 0) {
						np->next = hm[h];
						hm[h] = np;
					}
					else {
						np->next = hp[h];
						hp[h] = np;
					}
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				sum =  c[i] + d[j];
				if (sum <= 0) {
					h = -1*sum;
					h %= HASH;
					tp = hp[h];
				} else {
					h = sum%HASH;
					tp = hm[h];
				}
				while (tp) {
					if (tp->sum+sum == 0) {
						ans += tp->cnt;
						break;
					}
					tp = tp->next;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}