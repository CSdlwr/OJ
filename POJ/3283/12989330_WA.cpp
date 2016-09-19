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
char in[4];
int cnt;
Trie* root;

void insert(Trie* root, char* s) {
	int len = strlen(s);
	int po = *(s+len-1);
	Trie* rt = root;
	if (rt->next[po] == NULL) {
		rt->next[po] = (Trie*)malloc(sizeof(Trie));
		rt->next[po]->init();
	}
	rt = rt->next[po];
	if (len == 3) po = 10+'0';
	else po = *s;
	if (rt->next[po] == NULL) {
		rt->next[po] = (Trie*)malloc(sizeof(Trie));
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
			insert(root, in);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}