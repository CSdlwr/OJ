#include <iostream>
using namespace std;

int jc(int n);

int main() {
	printf("n e\n- -----------\n");
	int ans;
	double sum;
	printf("0 1\n1 2\n2 2.5\n");
	for (int i = 3; i <= 9; ++i) {
		sum = 0;
		for (int j = 0; j <= i; ++j) {
			ans = jc(j);
			sum += 1.0 / ans;
		}
		printf("%d %.9lf\n", i, sum);
	}
	return 0;
}

int jc(int n) {
	if (n == 0 || n == 1) return 1;
	int sum = n;
	for (int i = n - 1; i > 0; --i)
		sum *= i;
	return sum;
}