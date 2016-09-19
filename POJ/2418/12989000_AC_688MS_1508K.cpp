#include<iostream>
#include<string.h>
#include<malloc.h>
using namespace std;

struct Trie {
	int cnt;
	bool end;
	Trie* next[128];
	void init() {
		cnt = 0;
		end = false;
		memset(next, 0, sizeof(next));
	}
};

char in[35];
Trie* root;
int num = 0;

void insert(Trie* root, char* s) {
	Trie* rt = root;
	while (1) {
		if (rt->next[*s] == NULL) {
			rt->next[*s] = (Trie*)malloc(sizeof(Trie));
			rt->next[*s]->init();
		}
		rt = rt->next[*s];
		if (*(++s) == '\0') { 
			rt->cnt++; 
			rt->end = true;
			return ; 
		}
	}
}

void prtWord(Trie* rt, int p) {
	if (rt->end) {
		in[p] = '\0';
		printf("%s %.4f\n", in, rt->cnt*100.0/num);
		return;
	}
	for (int i = 0; i < 128; ++i)
	if (rt->next[i] != NULL) {
	in[p] = i;
	prtWord(rt->next[i], p+1);
	}
}

int main() {
	root = (Trie*)malloc(sizeof(Trie));
	root->init();
	while (gets(in)) {
		if (in[0] == '\0') break;
		++num;
		insert(root, in);
	}
	prtWord(root, 0);
	return 0;
}