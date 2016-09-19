#include<iostream>
#include<malloc.h>
using namespace std;

int *p;
int t, n;
int sw;

void swap(int *a, int *b) {
	int t = *a; 
	*a = *b;
	*b = t;
}
bool f;
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &n);
		sw = 0;
		p = (int *) malloc(sizeof(int)+1);
		for (int i = 1; i <= n; ++i) 
			scanf("%d", &p[i]);
		while (1) {
			f = false;
			for (int i = 1; i <= n; ++i) {
				if (p[i] != i) {
					++sw;
					swap(p+i, p+p[i]);
					f = true;
					break;
				}
			}
			if (!f) break;
		}
		
		printf("%d\n", sw);
		free(p);
	}
	return 0;
}