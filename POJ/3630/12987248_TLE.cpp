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
bool fg;

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
			t->next[*s-'0']->end = false;
			memset(t->next[*s-'0']->next, 0, 
				sizeof(t->next[*s-'0']->next));
		}
		if (*(s+1) == '\0') {
			t->next[*s-'0']->end = true;
			for (int i = 0; i < 10; ++i)
				if (t->next[*s-'0']->next[i] != NULL) return false;
			break;
		}
		t = t->next[*s-'0'];
		++s;
	}
	return true;
}

//bool judge(Tire* t) {
//	if (t->end) {
//		for (int i = 0; i < 10; ++i)
//			if (t->next[i] != NULL) {fg = true; return false;}
//	}
//	else for (int i = 0; i < 10; ++i)
//		if (!judge(t->next[i])) return false;
//	return true;
//}

int main() {

	char in[12];
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &n);
		root = (Tire*) malloc(sizeof(Tire));
		root->end = false;
		memset(root->next, 0, sizeof(root->next));
		fg = false;
		for (int i = 0; i < n; ++i) {
			scanf("%s", in);
			if (!insert(root, in)) fg = true;
		}
		if (fg) { printf("NO\n"); continue;}
//		else judge(root);
//		if (fg) printf("NO\n");
		else printf("YES\n");
		free(root);
	}
	return 0;
}
