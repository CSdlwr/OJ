#include<iostream>
using namespace std;
#define esp 1e-6
#define pi 3.14159265359

int t;
int n, f;
double r[10005];
double rm;
double l, h, m;
int cnt;
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d %d", &n, &f);
		++f;
		rm = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%lf", &r[i]);
			r[i] *= r[i];
			rm = rm < r[i] ? r[i] : rm;
		}
		h = rm; l = rm/f;
		while (h-l>esp) {
			m = (h+l)/2;
			cnt = 0;
			for (int i = 0; i < n; ++i)
				cnt += (int) r[i]/m;
			if (cnt < f) h = m;
			else l = m;
		}
		printf("%.4lf\n", m*pi);
	}
	return 0;
}