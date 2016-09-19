#include<iostream>
#include<string.h>
#include<malloc.h>
using namespace std;

int t, n;
struct Tire {
	Tire* next[11];
	int cnt;
	bool end;
};
Tire* root;

bool insert(Tire* root, char* s) {
	Tire* t = root;
	while (1) {
		if (t->next[*s-'0'] != NULL) {
			t->next[*s-'0']->cnt++;
			if (t->next[*s-'0']->end) return false;
		}
		else {
			t->next[*s-'0'] = (Tire*) malloc(sizeof(Tire));
			t->next[*s-'0']->cnt = 1;
			memset(t->next[*s-'0']->next, 0, 
				sizeof(t->next[*s-'0']->next));
		}
		if (*(s+1) == '\0') {
			t->next[*s-'0']->end = true;
			break;
		}
		t = t->next[*s-'0'];
		++s;
	}
	return true;
}

int main() {
	bool fg;
	char in[12];
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &n);
		root = (Tire*) malloc(sizeof(Tire));
		memset(root->next, 0, sizeof(root->next));
		fg = false;
		for (int i = 0; i < n; ++i) {
			scanf("%s", in);
			if (!insert(root, in)) fg = true;
		}
		if (fg) printf("NO\n");
		else printf("YES\n");
		free(root);
	}
	return 0;
}