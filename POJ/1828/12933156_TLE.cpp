#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define MAXN 50005

struct point {
	int x, y;
}pos[MAXN];

void swap(point* a, point* b);
int partition(point* po, int p, int r);
void qsort(point* po, int p, int r);

// bool cmp(point a, point b) {
// 	if (a.x < b.x) return true;
// 	return false;
// }

int main() {
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; ++i) 
			scanf("%d %d", &pos[i].x, &pos[i].y);
		//sort(pos, pos + n, cmp);
		qsort(pos, 0, n-1);
		//qsort(pos, n, sizeof(pos[0]), &cmp);
		int cnt = 1;
		int x = pos[n-1].x, y = pos[n-1].y;
		for (int i = n - 2; i >= 0; --i) {
			if (pos[i].x == x && pos[i].y > y)
				y = pos[i].y;
			else if (pos[i].y > y) {
				++cnt;
				y = pos[i].y;
				x = pos[i].x;
			}
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}



void swap(point* a, point* b) {
	point t = *a;
	*a = *b;
	*b = t;
}

int partition(point* po, int p, int r) {
	int i = p - 1;
	int j = p;
	while (j < r) {
		if (po[j].x < po[r].x) {
			++i;
			swap(po+i, po+j);
		}
		++j;
	}
	++i;
	swap(po+i, po+r);
	return i;
}

void qsort(point* po, int p, int r) {
	if (p < r) {
		int q = partition(po, p, r);
		qsort(po, p, q-1);
		qsort(po, q+1, r);
	}
}