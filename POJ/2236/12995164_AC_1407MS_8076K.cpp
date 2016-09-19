//#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
//using namespace std;

struct node {
	int x, y;
};

double dis[1005][1005];
node ns[1005];
int f[1005], r[1005];
int rs[1005];
int n;
double d;
int x, y;
char c;
int rsn = 0;

double getd(int i, int j) {
	if(dis[i][j ] != 0) return dis[i][j];
	double ix = ns[i].x, iy = ns[i].y;
	double jx = ns[j].x, jy = ns[j].y;
	dis[i][j] = sqrt((ix-jx)*(ix-jx) + (iy-jy)*(iy-jy));
	return dis[i][j];
}

int find(int x) {
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}

void us(int x, int y) {
	double dd = getd(x, y);
	int fx = find(x);
	int fy = find(y);
	if (dd <= d && fx != fy) {
		if (r[fx] >= r[fy]) {
			f[fy] = fx;
			r[fx] += r[fy];
		} else {
			f[fx] = fy;
			r[fy] += r[fx];
		}
	}
}

int main() {
	memset(dis, 0, sizeof(dis));
	scanf("%d %lf", &n, &d);
	getchar();
	for (int i = 1; i <= n; ++i) {
		r[i] = 1; f[i] = i;
		scanf("%d %d", &ns[i].x, &ns[i].y);
		getchar();
	}
	while (scanf("%c", &c) != EOF) {
		if (c == 'O') { 
			scanf(" %d", &x); getchar(); 
			for (int i = 0; i < rsn; ++i)
				us(rs[i], x);
			rs[rsn++] = x;
		}
		else {
			scanf(" %d %d", &x, &y);
			getchar();
			if (find(x) == find(y)) printf("SUCCESS\n");
			else printf("FAIL\n");
		}
	}
	return 0;
}