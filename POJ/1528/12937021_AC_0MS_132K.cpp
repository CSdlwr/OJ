#include <iostream>
using namespace std;

int main() {
	int inp;
	printf("PERFECTION OUTPUT\n");
	while (scanf("%d", &inp) != EOF) {
		if (inp == 0) break;
		int sum = 1;
		for (int i = 2; i < inp; ++i) 
			if (inp % i == 0) sum += i;
		if (inp == 1) {
			printf("%5d  DEFICIENT\n", inp);
			continue;
		}
		if (sum == inp) printf("%5d  PERFECT\n", inp);
		else if (sum < inp) printf("%5d  DEFICIENT\n", inp);
		else printf("%5d  ABUNDANT\n", inp);
	}
	printf("END OF OUTPUT");
	return 0;
}