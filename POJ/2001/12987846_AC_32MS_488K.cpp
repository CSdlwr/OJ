#include<iostream>
#include<malloc.h>
#include<string.h>
using namespace std;

struct Tire {
	Tire* next[27];
	int cnt;
	void init() {
	cnt = 0;
	memset(next, 0, sizeof(next));
	}
};

char in[1005][22];
char ans[22];
void insert(Tire* root, char* s) {
	Tire* rt = root;
	int i;
	while (*s != '\0') {
		i = *s-'a';
		if (rt->next[i] == NULL) {
		rt->next[i] = (Tire*) malloc(sizeof(Tire));
		rt->next[i]->init();
		}
		rt = rt->next[i];
		rt->cnt++;
		++s;
	}
}

void find(Tire* root, char* s) {
	Tire* rt = root;
	int i = *s - 'a';
	int d = 0;
	while (*s != '\0' 
		&& rt->next[i]->cnt > 1) {
		ans[d++] = i+'a';
		rt = rt->next[i];
		++s;
		i = *s-'a';
	}
	if (*s != '\0')
	ans[d++] = i+'a';
	ans[d] = '\0';
}

int main() {
	Tire* root = (Tire*) malloc(sizeof(Tire));
	root->init();
	int i = 0;
	while (scanf("%s", in[i]) != EOF) {
		if (in[i][0] == '\0') break;
		insert(root, in[i++]);
	}
	for (int ii = 0; ii < i; ++ii) {
		find(root, in[ii]);
		printf("%s %s\n", in[ii], ans);
	}
	return 0;
}