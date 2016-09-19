#include<iostream>
#include<malloc.h>
using namespace std;
#define HASH 1900001
struct node {
	int sum;
	int cnt;
	node* next;
};
node* hash[HASH];
int a1, a2, a3, a4, a5;
int sum, h, psum;
node *np, *tp;
bool fd;
int ans;
int main() {
	while (scanf("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5)) {
		ans = 0;
		for (int i = -50; i <= 50; ++i) {
			if (i == 0) continue;
			for (int j = -50; j <= 50; ++j) {
				if (j == 0) continue;
				for (int k = -50; k <= 50; ++k) {
					if (k == 0) continue;
					psum = sum = a1*i*i*i+a2*j*j*j+a3*k*k*k;
					fd = false;
					if (psum < 0) psum *= -1;
					h = psum%HASH;
					tp = hash[h];
					while (tp) {
						if (tp->sum == sum) {
							tp->cnt++;
							fd = true;
							break;
						}
						tp = tp->next;
					}
					if (!fd) {
						np = (node*) malloc(sizeof(node));
						np->sum = sum;
						np->cnt = 1;
						np->next = hash[h];
						hash[h] = np;
					}
				}
			}
		}
		for (int i = -50; i <= 50; ++i) {
			if (i == 0) continue;
			for (int j = -50; j <= 50; ++j) {
				if (j == 0) continue;
				psum = sum = a4*i*i*i+a5*j*j*j;
				if (psum < 0) psum *= -1;
				h = psum%HASH;
				tp = hash[h];
				while (tp) {
					if (sum+tp->sum == 0) {
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