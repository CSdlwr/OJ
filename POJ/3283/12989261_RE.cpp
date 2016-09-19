#include<iostream>
#include<malloc.h>
#include<string.h>
using namespace std;
struct Trie {
	Trie* next[128];
	void init() {
		memset(next, 0, sizeof(next));
	}
};

int t, n;
char in[3];
int cnt;
Trie* root;

void insert(Trie* root, char* s) {
	Trie* rt = root;
	while (1) {
		if (rt->next[*s] == NULL) {
			rt->next[*s] = (Trie*)malloc(sizeof(Trie));
			if (!(*s == 'D' || *s == 'H'
				|| *s == 'S' || *s == 'C')) ++cnt;
		}
		rt = rt->next[*s];
		if (*++s == '\0') return ;
	}
}

int main() {
	while (scanf("%d", &t)) {
		if (t == 0) break;
		root = (Trie*)malloc(sizeof(Trie));
		root->init();
		cnt = 0;
		while (t-- > 0) {
			scanf("%d", &n);
			for (int i = 0; i < n; ++i) {
			scanf("%s", in);
			insert(root, in);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}