#include<iostream>
#include<string.h>
#include<malloc.h>
using namespace std;
#define HASH 10007

struct node {
	int x, y;
	node* next;
};
node* hash[HASH];
int px[1005], py[1005];
int n;
node *np, *tp;
int h, h1;
bool f3, f4;
int ans;
bool find(int x3, int y3, int x4, int y4) {
	h = (x3*x3+y3*y3)%HASH;
	h1 = (x4*x4+y4*y4)%HASH;
	tp = hash[h];
	while (tp) {
		if (x3==tp->x && y3==tp->y) {
			f3 = true;
			break;
		}
		tp = tp->next;
	}
	tp = hash[h1];
	while (tp) {
		if (x4==tp->x && y4==tp->y) {
			f4 = true;
			break;
		}
		tp = tp->next;
	}
	if (f3 && f4) return true;
	return false;
}

int main() {
	while (scanf("%d", &n)) {
		if (n == 0) break;
		ans = 0;
		memset(hash, 0, sizeof(hash));
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &px[i], &py[i]);
			np = (node*) malloc(sizeof(node));
			np->x = px[i]; np->y = py[i];
			h = (px[i]*px[i]+py[i]*py[i])%HASH;
			np->next = hash[h];
			hash[h] = np;
		}
		int x3, x4, y3, y4;
		for (int i = 0; i < n-1; ++i) {
			for (int j = i+1; j < n; ++j) {
				f3 = f4 = false;
				x3 = px[i]+(py[i]-py[j]);
				y3 = py[i]-(px[i]-px[j]);
				x4 = px[j]+(py[i]-py[j]);
				y4 = py[j]-(px[i]-px[j]);
				if (x3 >= -20000 && x3 <= 20000
					&& x4 >= -20000 && x4 <= 20000
					&& y3 >= -20000 && y3 <= 20000
					&& y4 >= -20000 && y4 <= 20000) {
					if (find(x3, y3, x4, y4)) ans++;
				}
				f3 = f4 = false;
				x3 = px[i]-(py[i]-py[j]);
				y3 = py[i]+(px[i]-px[j]);
				x4 = px[j]-(py[i]-py[j]);
				y4 = py[j]+(px[i]-px[j]);
				if (x3 >= -20000 && x3 <= 20000
					&& x4 >= -20000 && x4 <= 20000
					&& y3 >= -20000 && y3 <= 20000
					&& y4 >= -20000 && y4 <= 20000) {
					if (find(x3, y3, x4, y4)) ans++;
				}
			}
		}
		printf("%d\n", ans>>2);
	}
	return 0;
}