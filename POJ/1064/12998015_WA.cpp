#include<iostream>
using namespace std;

int n, k;
double s[10005];
int ml = 0;

bool judge(double mid) {
	int g = 0;
	for (int i=0; i<n; ++i) 
		g += (int)s[i]*1000/mid;
	if (g < k) return false;
	return true;
}

int main() {
	int t;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &s[i]);
		t = s[i]*1000;
		ml = ml < t ? t : ml;
	}
	double mid;
	double h = ml, l = 1;
	while (l <= h) {
		mid = (l+h)/2;
		if (judge(mid)) l = mid+1;
		else h = mid-1;
	}
	if (mid < 10) printf("0.00\n");
	else printf("%.2lf\n", mid*1.0/1000);
	return 0;
}