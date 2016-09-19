#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define HASH 10007

struct node {
	char smp[8];
	int cnt;
	char w[100][10];
	node* next;
};
node* hash[HASH];
char in[10];
int h, l;
bool fd;
node *np, *tp;

void swap(char* a, char* b) {
	char t = *a;
	*a = *b;
	*b = t;
}

int partition(char a[], int p, int r) {
	int i = p-1;
	int j = p;
	char x = a[r];
	while (j < r) {
		if (a[j] < x) {
			++i;
			swap(a+i, a+j);
		}
		++j;
	}
	++i;
	swap(a+i, a+r);
	return i;
}

void qsort_(char a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		qsort_(a, p, q-1);
		qsort_(a, q+1, r);
	}
}

int hash_(char* str) {
	int hash = 0, l = strlen(str);
	for (int i = 0; i < l; ++i)
		hash += str[i];
	return hash%HASH;
}

int cmp(const void *a, const void *b) {
	return strcmp(*(char **)a, *(char **)b);
}

void qs(char str[100][10],int n){
	char temp[20];
	int i=0;
	int j=0;
	int min=i;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i;j<n;j++){
			if(  strcmp(str[j],str[min])==-1  ){
				min=j;
			}
		}
		strcpy(temp,str[i]);
		strcpy(str[i],str[min]);
		strcpy(str[min],temp);

	}
}

int main() {
	char smp[10];
	while (gets(in))  {
		if (strcmp(in, "XXXXXX") == 0) break;
		h = hash_(in);
		strcpy(smp, in);
		l = strlen(in);
		qsort_(smp, 0, l-1);
		tp = hash[h];
		fd = false;
		while (tp) {
			if (strcmp(smp, tp->smp) == 0) {
				strcpy(tp->w[tp->cnt], in); 
				tp->cnt++;
				fd = true;
				break;
			}
			tp = tp->next;
		}
		if (!fd) {
			np = (node*)malloc(sizeof(node));
			strcpy(np->smp, smp);
			np->cnt = 0;
			strcpy(np->w[np->cnt], in);
			np->cnt++;
			np->next = hash[h];
			hash[h] = np;
		}
	}
	while (gets(in)) {
		if (strcmp(in, "XXXXXX") == 0) break;
		l = strlen(in);
		strcpy(smp, in);
		qsort_(smp, 0, l-1);
		h = hash_(in);
		tp = hash[h];
		fd = false;
		while (tp) {
			if (strcmp(smp, tp->smp) == 0) {
				int len = tp->cnt;
				qs(tp->w, tp->cnt);
				for (int i = 0; i < len; ++i) 
					printf("%s\n", tp->w[i]);
				fd = true;
				printf("******\n");
				break;
			}
			tp = tp->next;
		}
		if (!fd) printf("NOT A VALID WORD\n******\n");
	}
	
	return 0;
}