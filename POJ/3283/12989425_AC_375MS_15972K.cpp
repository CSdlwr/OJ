#include<iostream>
#include<malloc.h>
#include<string.h>
using namespace std;
struct Trie {
	Trie* next[55];
	void init() {
		memset(next, 0, sizeof(next));
	}
};

int t, n;
char in[4];
//int po[100005];
int* po;
int cnt;
Trie* root;

int getPo(char* s) {
	int p;
	if (*s == 'A') p = 0;
	else if (*s == 'J') p = 10;
	else if (*s == 'Q') p = 11;
	else if (*s == 'K') p = 12;
	else p = *s-'1';
	if (*++s == '0') { p = 9; ++s;}
	if (*s == 'D') p += 13;
	else if (*s == 'H') p += 26;
	else if (*s == 'S') p += 39;
	return p;
}

void insert(Trie* root, int po[], int n) {
	Trie* rt = root;
	for (int i = 0; i < n; ++i) {
		if (rt->next[po[i]] == NULL) {
			++cnt;
			rt->next[po[i]] = (Trie*)malloc(sizeof(Trie));
			rt->next[po[i]]->init();
		}
		rt = rt->next[po[i]];
	}
}

void delM(Trie* rt) {
	for (int i = 0; i < 55; ++i) 
	if (rt->next[i] != NULL) delM(rt->next[i]);
	free(rt);
}

int main() {
	while (scanf("%d", &t)) {
		if (t == 0) break;
		root = (Trie*)malloc(sizeof(Trie));
		root->init();
		cnt = 0;
		while (t-- > 0) {
			scanf("%d", &n);
			po = new int[n];
			for (int i = 0; i < n; ++i) {
			scanf("%s", in);
			po[n-i-1] = getPo(in);
			}
			insert(root, po, n);
		}
		delM(root);
		printf("%d\n", cnt);
	}
	return 0;
}