#include<iostream>
#include<string.h>
#include<malloc.h>
using namespace std;

struct Trie {
	bool end;
	int cnt;
	Trie* next[5];
	void init() {
		end = false;
		cnt = 0;
		memset(next, 0, sizeof(next));
	}
};

short ans[20005];
Trie* root;
int n, m;
char in[22];

int getPo(char c) {
	if (c == 'A') return 0;
	else if (c == 'C') return 1;
	else if (c == 'G') return 2;
	else return 3;
}

void insert(Trie* root, char* s) {
	Trie* rt = root;
	int ps;
	while (*s != '\0') {
		ps = getPo(*s);
		if (rt->next[ps] == NULL) {
			rt->next[ps] = (Trie*) malloc(sizeof(Trie));
			rt->next[ps]->init();
		}
		rt = rt->next[ps];
		if (*(++s) == '\0') { 
		rt->cnt++; rt->end = true;
		return ; 
		}
	}
}

void find(Trie* root) {
	Trie* rt = root;
	if (rt->end) { ans[rt->cnt]++; return ; }
	for (int i = 0; i < 4; ++i)
	if (rt->next[i] != NULL)
		find(rt->next[i]);
}

void freeM(Trie* root) {
//	if (root->end) { free(root); return ; }
	Trie* rt = root;
	for (int i = 0; i < 4; ++i)
	if (root->next[i] != NULL)
	freeM(root->next[i]);
	free(root);
}

int main() {
	while (scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0) break;
		root = (Trie*) malloc(sizeof(Trie));
		root->init();
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < n; ++i) {
		scanf("%s", in);
		insert(root, in);
		}
		find(root);
		freeM(root);
		for (int i = 1; i <= n; ++i)
		printf("%d\n", ans[i]);
	}
	return 0;
}