#include<iostream>
#include<malloc.h>
using namespace std;
#define HASH_SIZE 90001

struct node {
	int arm[6];
	node* next;
};
node* hash[HASH_SIZE];
int n;
int in[6];
bool fd = false;

bool same(int a[], int b[]) {
	for (int i = 0; i < 6; ++i) {
		if (a[0] == b[i]
		&& a[1] == b[(i+1)%6]
		&& a[2] == b[(i+2)%6]
		&& a[3] == b[(i+3)%6]
		&& a[4] == b[(i+4)%6]
		&& a[5] == b[(i+5)%6] ||
		a[0] == b[i]
		&& a[1] == b[(i-1+6)%6]
		&& a[2] == b[(i-2+6)%6]
		&& a[3] == b[(i-3+6)%6]
		&& a[4] == b[(i-4+6)%6]
		&& a[5] == b[(i-5+6)%6])
			return true;
	}
	return false;
}

int BRKDhash(int a[]) {
	int sum = 0;
	for (int i = 0; i < 6; ++i) 
		sum += a[i];
	return sum % HASH_SIZE;
}

int main() {
	int h;
	node* np;
	node* tp;
	scanf("%d", &n);
	while (n-- > 0) {
		scanf("%d %d %d %d %d %d", &in[0], &in[1], &in[2], &in[3], &in[4], &in[5]);
		if (!fd) {
			h = BRKDhash(in);
			np = (node*) malloc(sizeof(node));
			np->next = hash[h];
			hash[h] = np;
			tp = np->next;
			while (tp) {
				if (same(in, tp->arm)) {
					fd = true;
					break;
				}
				tp = tp->next;
			}
			for (int i = 0; i < 6; ++i)
				np->arm[i] = in[i];
		}
	}
	if (fd) printf("Twin snowflakes found.\n");
	else printf("No two snowflakes are alike.\n");
	return 0;
}