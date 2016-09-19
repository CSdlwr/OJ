#include<iostream>
#include<string.h>
#include<malloc.h>
using namespace std;

int t, n;
//struct Tire {
//	Tire* next[11];
//	int cnt;
//	bool end;
//};
//Tire* root;
bool fg;
int num;
int root;
struct Tire {
	int next[11];
	bool end;
	void init() {
		end = false;
		for (int i = 0; i < 11; ++i)
		next[i] = -1;
	}
};

Tire ts[1<<16];

bool insert(char *s) {
	int rt = root;
	while (true) {
		if (ts[rt].next[*s-'0'] != -1) {
			if (ts[rt].end) return false;
		}
		else {
			ts[++num].init();
			ts[rt].next[*s-'0'] = num;
		}
		if (*(s+1) == '\0') {
			ts[rt].end = true;
			for (int i = 0; i < 10; ++i)
			if (ts[ts[rt].next[*s-'0']].next[i] != -1) return false;
			break;
		}
		rt = ts[rt].next[*s-'0'];
		++s;
	}
	return true;
}

int main() {
	char in[12];
	scanf("%d", &t);
	while (t-- > 0) {
		num = 0;
		scanf("%d", &n);
		root = 0;
		ts[root].init();
		fg = false;
		for (int i = 0; i < n; ++i) {
			scanf("%s", in);
			if (!insert(in)) fg = true;
		}
		if (fg) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}