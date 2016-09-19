#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1100

int main() {
	int m;
	scanf("%d", &m);
	while (m-- > 0) {
		int n, k, count = 0;
		int input[MAX_N];
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) 
			scanf("%d", &input[i]);
		while (next_permutation(input, input+n)) 
			if (++count == k) break;
		while (k != count) {
			for (int i = 0; i < n; ++i)
				input[i] = i + 1;
			count++;
			while (next_permutation(input, input + n))
				if (++count == k) break;
		}
		for (int i = 0; i < n; ++i)
			printf("%d ", input[i]);
		printf("\n");
	}
	return 0;
}