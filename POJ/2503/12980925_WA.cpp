#include<iostream>
#include<string.h>
#include<malloc.h>
using namespace std;
#define HASH_SIZE 10003

struct node {
	int i;
	node* next;
};
node* hash[HASH_SIZE];
char dic[100005][11];
char wd[100005][11];
char s1[11];
int ls2;
int d = 26, h, t;

int BKDRhash(char* str) {
	unsigned long hash = 0;
	int seed = 131;
	int l = strlen(str);
	for (int i = 0; i < l; ++i)
		hash = hash*seed + str[i];
	return hash%HASH_SIZE;
}

int main () {
	int h, cnt = 0, ti = 0;
	while (gets(s1)) {
		if (s1[0] == '\0') break;
		sscanf(s1, "%s%s", dic[cnt], wd[cnt]);
		h = BKDRhash(wd[cnt]);
		node* np = (node*) malloc(sizeof(node));
		np->next = hash[h];
		hash[h] = np;
		np->i = cnt++;
	}
	bool fd;
	while (scanf("%s", s1) != EOF) {
		fd = false;
		h = BKDRhash(s1);
		node* tp = hash[h];
		while (tp) {
			if (strcmp(wd[tp->i], s1) == 0) {
				printf("%s\n", dic[tp->i]);
				fd = true;
				break;
			}
			tp = tp->next;
		}
		if (!fd) printf("eh\n");
	}
	return 0;
}