#include <iostream>
using namespace std;
#define INF 999999999

struct board {
	int x1, x2, h;
	int ml, mr;
}bos[1005];

int hasBoardUnderHere(int x, int y, int bn);
int min(int a, int b);
int minTimeFromHere(int x, int y, int bn);
int partition(board* a, int p, int r);
void qsort(board* a, int p, int r);
void swap(board* b1, board* b2);
int n, x, y, m;

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d %d %d %d", &n, &x, &y, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d %d", &bos[i].x1, &bos[i].x2, &bos[i].h);
			bos[i].mr = -1;
			bos[i].ml = -1;
		}
		qsort(bos, 0, n-1);
		bos[0].mr = bos[0].ml = bos[0].h;
		printf("%d\n", minTimeFromHere(x, y, n-1));
	}
	return 0;
}

int minTimeFromHere(int x, int y, int bn) {
	int time = 0;
	int i = hasBoardUnderHere(x, y, bn);
	if (i >= 0) {
		int l, r;
		time = y - bos[i].h;
		if (bos[i].ml != -1) 
			l = bos[i].ml;
		else if (bos[i].ml == INF)
			l = INF;
		else {
			l = minTimeFromHere(bos[i].x1, bos[i].h, bn-1);
			bos[i].ml = l;
		}
		if (bos[i].mr != -1)
			r = bos[i].mr;
		else if (bos[i].mr == INF)
			r = INF;
		else {
			r = minTimeFromHere(bos[i].x2, bos[i].h, bn-1);
			bos[i].mr = r;
		}
		time += min(x - bos[i].x1 + l, bos[i].x2 - x + r);
	} else if (y <= m)
		time = y;
	else time = INF;
// 		else {
// 			l = x - bos[i].x1 + minTimeFromHere(bos[i].x1, bos[i].h, bn-1);
// 			r = bos[i].x2 - x + minTimeFromHere(bos[i].x2, bos[i].h, bn-1);
// 			int mt = min(l, r);
// 			time += mt;
// 			bos[i].mint = mt;
// 		}
// 	} else if (y <= m) 
// 		time = y;
// 	else
// 		time = INF;
	return time;
}

int hasBoardUnderHere(int x, int y, int bn) {
	for (int i = bn; i >= 0; --i) 
		if (bos[i].h < y && y - bos[i].h <= m 
			&& bos[i].x1 <= x && bos[i].x2 >= x)
			return i;
	return -1;
}

void qsort(board* a, int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		qsort(a, p, q-1);
		qsort(a, q+1, r);
	}
}

void swap(board* b1, board* b2) {
	board t = *b1;
	*b1 = *b2;
	*b2 = t;
}

int partition(board* a, int p, int r) {
	int i = p - 1;
	int j = p;
	int x = a[r].h;
	while (j < r) {
		if (a[j].h <= x) {
			++i;
			swap(a+i, a+j);
		}
		++j;
	}
	++i;
	swap(a+i, a+r);
	return i;
}

int min(int a, int b) {
	return a > b ? b : a;
}