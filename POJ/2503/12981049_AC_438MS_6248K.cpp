#include<iostream>
#include<string.h>
#include<malloc.h>
using namespace std;
#define HASH_SIZE 10003

struct node {
	int i;
	node* next;
};
node* hash[HASH_SIZE+1];
char dic[100005][15];
char wd[100005][15];
char s1[25];

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
	node* np;
	while (gets(s1)) {
		if (s1[0] == '\0') break;
		sscanf(s1, "%s %s", dic[cnt], wd[cnt]);
		h = BKDRhash(wd[cnt]);
		np = (node*) malloc(sizeof(node));
		np->next = hash[h];
		hash[h] = np;
		np->i = cnt++;
	}
	bool fd;
	while (gets(s1)) {
		fd = false;
		h = BKDRhash(s1);
		np = hash[h];
		while (np) {
			if (strcmp(wd[np->i], s1) == 0) {
				printf("%s\n", dic[np->i]);
				fd = true;
				break;
			}
			np = np->next;
		}
		if (!fd) printf("eh\n");
	}
	return 0;
}