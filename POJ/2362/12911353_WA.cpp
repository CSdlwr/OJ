#include <iostream>
using namespace std;
#define MAXM 25

int side = 0, num = 0;
int mp[MAXM];
bool vs[MAXM];
bool flag = false;
int n = 0, m = 0;

void dfs(int start, int len, int root);
void swap(int* A, int i, int j);
int partition(int *A, int p, int r);
void qsort(int *A, int p, int r);

 int main() {
 	int sum = 0, max = 0;
 	scanf("%d", &n);
 	while (n-- > 0) {
		flag = false;
		sum = 0;
		max = 0;
		num = 0;
 		scanf("%d", &m);
 		for (int i = 0; i < m; ++i) {
 			scanf("%d", &mp[i]);
 			sum += mp[i];
 			max = max < mp[i] ? mp[i] : max;
 		}
 		side = sum / 4;
 		if (sum % 4 || max > side) {
 			printf("no\n");
 			continue;
 		}
 		qsort(mp, 0, m-1);
 		memset(vs, 1, sizeof(vs));
 		dfs(0, 0, 0);
 		if (flag) printf("yes\n");
 		else printf("no\n");
 	}
 	return 0;
 }

//  
//  int main() {
//  	int A[] = {5, 7, 1, 4, 6, 2};
//  	qsort(A, 0, 5);
//  	for (int i = 0; i < 6; ++i)
//  		printf("%d ", A[i]);
//  }

void dfs(int start, int len, int root) {
	if (flag)
		return ;
	if (len == side) {
		++num;
		if (num == 4) {
			flag = true;
			return ;
		}
		int j = 0; 
		while (!vs[j++]) ;
		dfs(j, 0, j);
		return ;
	}
	for (int i = start; i < m; ++i) {
		if (vs[i] && mp[i] + len <= side) {
			vs[i] = false;
			dfs(i + 1, len + mp[i], root);
			if (flag)
				return ;
			if (len + mp[i] == side) num--;
			vs[i] = true;
			while (mp[i] == mp[i+1]) ++i;
		}
		if (vs[root])
			return ;
	}
}

void swap(int* A, int i, int j) {
	int t = A[i];
	A[i] = A[j];
	A[j] = t;
}

int partition(int *A, int p, int r) {
	int i = p - 1, j;
	for (j = p; j < r; ++j) {
		if (A[j] >= A[r]) 
			swap(A, ++i, j);
	}
	swap(A, r, ++i);
	return i;
}

void qsort(int *A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		qsort(A, p, q - 1);
		qsort(A, q + 1, r);
	}
}
