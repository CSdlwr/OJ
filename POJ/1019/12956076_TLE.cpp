#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	int i, j, k;
	while (t-- > 0) {
		scanf("%d", &i);
		j = 0;
		k = 1;
		while (j < i) 
			j += k++;
		j -= k - 1;
		printf("%d\n", i-j);
	}
	return 0;
}