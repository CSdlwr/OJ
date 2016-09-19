#include <iostream>
using namespace std;

float cal(float a, float b, char op);

int ops[5] = {'+', '-', '*', '/'};
int main() {
	float a, b, c, d;
	scanf("%f %f %f %f", &a, &b, &c, &d);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k) {
				if (cal(cal(cal(a, b, ops[i]), c, ops[j]), d, ops[k]) - 24 == 0) {
					printf("((%.0f%c%.0f)%c%.0f)%c%.0f", a, ops[i], b, ops[j], c, ops[k], d);
				} else if (cal(cal(a, cal(b, c, ops[i]), ops[j]), d, ops[k]) - 24 == 0) {
					printf("(%.0f%c(%.0f%c%.0f))%c%.0f", a, ops[j], b, ops[i], c, ops[k], d);
				} else if (cal(a, cal(b, cal(c, d, ops[i]), ops[j]), ops[k]) - 24 == 0) {
					printf("%.0f%c(%.0f%c(%.0f%c%.0f))", a, ops[k], b, ops[j], c, ops[i], d);
				} else if (cal(cal(a, b, ops[i]), cal(c, d, ops[j]), ops[k]) - 24 == 0) {
					printf("(%.0f%c%.0f)%c(%.0f%c%.0f)", a, ops[i], b, ops[k], c, ops[j], d);
				} else if (cal(a, cal(cal(b, c, ops[i]), d, ops[j]), ops[k]) - 24 == 0) {
					printf("%.0f%c((%.0f%c%.0f)%c%.0f)", a, ops[j], b, ops[i], c, ops[k], d);
				}
			}
	}
	return 0;
}

float cal(float a, float b, char op) {
	switch(op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}