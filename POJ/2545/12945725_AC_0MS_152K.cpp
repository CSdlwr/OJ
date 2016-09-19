#include <iostream>
using namespace std;

long long min(long long a, long long b, long long c);
int main() {
	long long p1, p2, p3, i;
	scanf("%I64d %I64d %I64d %I64d", &p1, &p2, &p3, &i);
	long long* n = new long long[i+5];
	n[0] = 1;
	int i1 = 0, i2 = 0, i3 = 0;
	long long v1, v2, v3;
	for (int ii = 1; ii <= i; ++ii) {
		v1 = n[i1]*p1;
		v2 = n[i2]*p2;
		v3 = n[i3]*p3;
		n[ii] = min(v1, v2, v3);
		if (v1 == n[ii]) ++i1;
		if (v2 == n[ii]) ++i2;
		if (v3 == n[ii]) ++i3;
	}
	printf("%I64d\n", n[i]);
	return 0;
}

long long min(long long a, long long b, long long c) {
	long long m = a > b ? b : a;
	return m > c ? c : m;
}