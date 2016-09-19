
#include <iostream>
using namespace std;
#define INF 999999999

struct board {
	int x1, x2, h;
}bos[1005];

int hasBoardUnderHere(int x, int y);
int min(int a, int b);
int minTimeFromHere(int x, int y);
int partition(board* a, int p, int r);
void qsort(board* a, int p, int r);
void swap(board* b1, board* b2);
int n, x, y, m;

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d %d %d %d", &n, &x, &y, &m);
		for (int i = 0; i < n; ++i) 
			scanf("%d %d %d", &bos[i].x1, &bos[i].x2, &bos[i].h);
		qsort(bos, 0, n-1);
		printf("%d\n", minTimeFromHere(x, y));
	}
	return 0;
}

int minTimeFromHere(int x, int y) {
	int time = 0;
	int i = hasBoardUnderHere(x, y);
	if (i >= 0) {
		int l, r;
		time = y - bos[i].h;
		l = x - bos[i].x1 + minTimeFromHere(bos[i].x1, bos[i].h);
		r = bos[i].x2 - x + minTimeFromHere(bos[i].x2, bos[i].h);
		time += min(l, r);
	} else if (y <= m) 
		time = y;
	else
		time = INF;
	return time;
}

int hasBoardUnderHere(int x, int y) {
	for (int i = n-1; i >= 0; --i) 
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
	swap(a[++i], a[r]);
	return i;
}

int min(int a, int b) {
	return a > b ? b : a;
}