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
	if (rt->next[*s] == NULL) {
		rt->next[*s] = (Trie*)malloc(sizeof(Trie));
		rt->next[*s]->init();
	}
	rt = rt->next[*s];
	if (rt->next[*--s] == NULL) {
		rt->next[*s] = (Trie*)malloc(sizeof(Trie));
		++cnt;
		return ;
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
			insert(root, in+1);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}