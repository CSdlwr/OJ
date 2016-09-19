#include<iostream>
using namespace std;
#define INF 0x0f0f0f0f
int getIndex(char* a);
double prim();
double w[800][800];
char name[800][20];
double total;
int n, m;
int main() {
	scanf("%lf", &total);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", name[i]);
	scanf("%d", &m);
	char tn1[20], tn2[20];
	int v1, v2;
	double c;
	//memset(w, 0x0f, sizeof(w));
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			w[i][j] = w[j][i] = INF;
	for (int i = 0; i < m; ++i) {
		scanf("%s%s%lf", tn1, tn2, &c);
		v1 = getIndex(tn1);
		v2 = getIndex(tn2);
		w[v1][v2] = w[v2][v1] = c;
	}
	double ans = prim();
	if (ans > total) printf("Not enough cable\n");
	else printf("Need %.1lf miles of cable\n", ans);
	return 0;
}

double prim() {
	double sum = 0;
	double k[800];
	bool vs[800];
	memset(vs, 0, sizeof(vs));
	//memset(k, 0x0f, sizeof(k));
	for (int i = 1; i < n; ++i)
		k[i] = INF;
	k[0] = 0;
	double min;
	int v;
	for (int i = 0; i < n; ++i) {
		min = INF;
		v = -1;
		for (int j = 0; j < n; ++j) {
			if (!vs[j] && k[j] < min) {
				min = k[j];
				v = j;
			}
		}
		if (v == -1) break;
		vs[v] = true;
		sum += k[v];
		for (int j = 0; j < n; ++j) 
			if (!vs[j] && w[v][j] < k[j])
				k[j] = w[v][j];
	}
	return sum;
}

int getIndex(char* a) {
	for (int i = 0; i < n; ++i)
		if (strcmp(a, name[i]) == 0)
			return i;
}