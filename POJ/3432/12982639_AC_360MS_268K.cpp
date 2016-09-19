#include<iostream>
#include<malloc.h>
#include<string.h>
using namespace std;
#define HASH 10007

struct node {
	int x, y;
	node* next;
};
node* hash[HASH];
int px[2005], py[2005];
int n;
node *np, *tp;
int h1, h2;
bool f3, f4;
int ans;
bool find(int x3, int y3, int x4, int y4) {
	h1 = (x3*x3+y3*y3)%HASH;
	h2 = (x4*x4+y4*y4)%HASH;
	tp = hash[h1];
	while (tp) {
		if (tp->x == x3 && tp->y == y3) {
			f3 = true;
			break;
		}
		tp = tp->next;
	}
	tp = hash[h2];
	while (tp) {
		if (tp->x == x4 && tp->y == y4) {
			f4 = true;
			break;
		}
		tp = tp->next;
	}
	if (f3 && f4) return true;
	return false;
}

int main() {
	while (scanf("%d", &n) != EOF) {
		ans = 0;
		memset(hash, 0, sizeof(hash));
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &px[i], &py[i]);
			int h1 = (px[i]*px[i] + py[i]*py[i])%HASH;
			np = (node*)malloc(sizeof(node));
			np->x = px[i]; np->y = py[i];
			np->next = hash[h1];
			hash[h1] = np;
		}
		int dx, dy;
		int x3, y3, x4, y4;
		for (int i = 0; i < n-1; ++i) {
			for (int j = i+1; j < n; ++j) {
				dx = px[i]-px[j];
				dy = py[i]-py[j];
				f3 = f4 = false;
				x3 = px[i] + dy;
				y3 = py[i] - dx;
				x4 = px[j] + dy;
				y4 = py[j] - dx;
				if (find(x3, y3, x4, y4)) ++ans;
				
				f3 = f4 = false;
				x3 = px[i] - dy;
				y3 = py[i] + dx;
				x4 = px[j] - dy;
				y4 = py[j] + dx;
				if (find(x3, y3, x4, y4)) ++ans;
			}
		}
		printf("%d\n", ans>>2);
	}
	return 0;
}