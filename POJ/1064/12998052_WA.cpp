#include<iostream>
using namespace std;

int n, k;
int s[10005];
int ml = 0;

bool judge(double mid) {
	int g = 0;
	for (int i=0; i<n; ++i) 
		g += (int)s[i]/mid;
	if (g < k) return false;
	return true;
}

int main() {
	double t;
	int sum = 0;
	while (scanf("%d %d", &n, &k) != EOF) {
		ml = sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%lf", &t);
			s[i] = (int) (t*100);
			sum += s[i];
			ml = ml < s[i] ? s[i] : ml;
		}
		if (sum < k) {printf("0.00\n"); continue;}
		int mid;
		int h = ml, l = 0;
		while (l <= h) {
			mid = (l+h)/2;
			if (judge(mid)) l = mid+1;
			else h = mid-1;
		}
		printf("%.2lf\n", h*1.0/100);
	}
	return 0;
}