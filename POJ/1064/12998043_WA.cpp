#include<iostream>
using namespace std;

int n, k;
double s[10005];
int ml = 0;

bool judge(double mid) {
	int g = 0;
	for (int i=0; i<n; ++i) 
		g += (int)s[i]/(mid/100.0);
	if (g < k) return false;
	return true;
}

int main() {
	int t, sum;;
	while (scanf("%d %d", &n, &k) != EOF) {
		ml = sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%lf", &s[i]);
			t = s[i]*100;
			sum += t;
			ml = ml < t ? t : ml;
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