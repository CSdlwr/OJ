#include <iostream>
using namespace std;

int main() {
	float t, t1;
	scanf("%f", &t);
	while (scanf("%f", &t1)) {
		if (t1 == 999) break;
		printf("%.2f\n", t1-t);
		t = t1;
	}
	printf("End of Output\n");
	return 0;
}